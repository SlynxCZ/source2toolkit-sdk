/**

* @file schema.h
* @brief Schema system utilities for accessing and modifying entity fields.
*
* Provides:
* * Runtime field offset resolution (via SchemaSystem)
* * Safe access to entity properties
* * Automatic network state updates
* * Compile-time hashing for fast lookup
*
* @note This system is similar to Source2 schema/netvar access.
  */

#pragma once

#include "igameevents.h"
#include "igameeventsystem.h"
#include "schemasystem.h"
#include "entity2/entityclass.h"
#include "entity2/entitysystem.h"
#include "entity2/entityidentity.h"
#include "entity2/entityinstance.h"
#include "const.h"
#include "tier0/dbg.h"

#include <type_traits>
#include <cstdint>

/* =========================
Engine interface getters
========================= */

/**

* @brief Global accessors for engine interfaces.
  */
IGameEventManager2* GetGameEventManager();
CGlobalVars* GetGlobalVars();
ICvar* GetCVar();
ISource2Server* GetSource2Server();
IVEngineServer* GetEngineServer();
IGameEventSystem* GetGameEventSystem();
INetworkMessages* GetNetworkMessages();
INetworkServerService* GetNetworkServerService();
CGameEntitySystem* GetEntitySystem();
CSchemaSystem* GetSchemaSystem();

/* =========================
Schema core types
========================= */

/**

* @brief Represents schema offset information.
  */
struct SchemaKey
{
    /// Offset of the field
    int32 offset;

    /// True if field is networked
    bool networked;
};

/**

* @brief Helper for networked variable propagation.
  */
class CNetworkVarChainer2
{
public:
    CEntityInstance* m_pEntity;

private:
    uint8 pad_0000[24];

public:
    ChangeAccessorFieldPathIndex_t m_PathIndex;

private:
    uint8 pad_0024[4];
};

/* =========================
Strong handle wrapper
========================= */

/**

* @brief Lightweight wrapper for entity pointers.
  */
template <typename T>
class CStrongHandle
{
private:
    T* m_pValue;

public:
    T* Get() const { return m_pValue; }
    void Set(void* pPtr) { m_pValue = pPtr; }

    bool IsValid() const { return m_pValue != nullptr; }

    T* operator->() const { return m_pValue; }
    operator T*() const { return m_pValue; }
};

/* =========================
Network state helpers
========================= */

void EntityNetworkStateChanged(uintptr_t pEntity, uint nOffset);
void ChainNetworkStateChanged(uintptr_t pNetworkVarChainer, uint nOffset);
void NetworkVarStateChanged(uintptr_t pNetworkVar, uint32_t nOffset, uint32 nNetworkStateChangedOffset);

/* =========================
Schema API
========================= */

namespace schema
{
    /**
    * @brief Finds chain offset for a class.
    */
    int16_t FindChainOffset(const char* className, uint32_t classNameHash);

    int16_t FindChainOffset(const char* className);

    /**
     * @brief Gets schema offset for a field.
     */
    SchemaKey GetOffset(const char* className, uint32_t classKey,
                        const char* memberName, uint32_t memberKey);

    /**
     * @brief Gets server offset (fallback).
     */
    int32_t GetServerOffset(const char* pszClassName, const char* pszPropName);

    /**
     * @brief Gets class size.
     */
    int32_t GetClassSize(const char* className);

    /**
     * @brief Marks field as changed (network update).
     */
    void SetStateChanged(CEntityInstance* entity, const char* className, const char* propName);
}

/* =========================
Compile-time hashing
========================= */

/**

* @brief FNV-1a 32-bit hash (constexpr).
  */
inline constexpr uint32_t hash_32_fnv1a_const(const char* const str,
                                              const uint32_t value = 0x811c9dc5) noexcept
{
    return (str[0] == '\0')
               ? value
               : hash_32_fnv1a_const(&str[1], (value ^ uint32_t(str[0])) * 0x1000193);
}

/**

* @brief FNV-1a 64-bit hash (constexpr).
  */
inline constexpr uint64_t hash_64_fnv1a_const(const char* const str,
                                              const uint64_t value = 0xcbf29ce484222325) noexcept
{
    return (str[0] == '\0')
               ? value
               : hash_64_fnv1a_const(&str[1], (value ^ uint64_t(str[0])) * 0x100000001b3);
}

/* =========================
Writable trait
========================= */

/**

* @brief Determines if schema field can be written directly.
  */
template <typename T>
inline constexpr bool schema_writable_v =
    std::is_pointer_v<T> ||
    std::is_trivially_copyable_v<T> ||
    std::is_same_v<T, Vector> ||
    std::is_same_v<T, QAngle> ||
    std::is_same_v<T, Color>;

/* =========================
Schema field macros
========================= */

#define SCHEMA_FIELD_OFFSET(type, varName, extra_offset)                                                                     \
	class varName##_prop                                                                                                     \
	{                                                                                                                        \
	public:                                                                                                                  \
		std::add_lvalue_reference_t<type> Get()                                                                              \
		{                                                                                                                    \
			static const auto m_key = schema::GetOffset(m_className, m_classNameHash, #varName, m_varNameHash);              \
			static const auto m_offset = offsetof(ThisClass, varName);														 \
																															 \
			uintptr_t pThisClass = ((uintptr_t)this - m_offset);                                                             \
                                                                                                                             \
			return *reinterpret_cast<std::add_pointer_t<type>>(pThisClass + m_key.offset + extra_offset);                    \
		}                                                                                                                    \
		template <typename T = type>                                                                                         \
		std::enable_if_t<std::is_pointer_v<T>, void>                                                                         \
		Set(T val)                                                                                                           \
		{                                                                                                                    \
			static const auto m_key = schema::GetOffset(m_className, m_classNameHash, #varName, m_varNameHash);              \
			static const auto m_offset = offsetof(ThisClass, varName);                                                       \
																															 \
			uintptr_t pThisClass = ((uintptr_t)this - m_offset);                                                             \
																															 \
			NetworkStateChanged();                                                                                           \
			*reinterpret_cast<T*>(pThisClass + m_key.offset + extra_offset) = val;                                           \
		}																													 \
		template <typename T = type>                                                                                         \
		std::enable_if_t<!std::is_pointer_v<T> && std::is_trivially_copyable_v<T>, void>                                     \
		Set(T val)                                                                                                           \
	    {                                                                                                                    \
    		static const auto m_key = schema::GetOffset(m_className, m_classNameHash, #varName, m_varNameHash);              \
			static const auto m_offset = offsetof(ThisClass, varName);                                                       \
																															 \
			uintptr_t pThisClass = ((uintptr_t)this - m_offset);                                                             \
																															 \
			NetworkStateChanged();                                                                                           \
			*reinterpret_cast<T*>(pThisClass + m_key.offset + extra_offset) = val;                                           \
		}																													 \
		template <typename T = type>                                                                                         \
		std::enable_if_t<!std::is_pointer_v<T> && !std::is_trivially_copyable_v<T>, void>                                    \
		Set(const T& val)                                                                                                    \
		{                                                                                                                    \
			static const auto m_key = schema::GetOffset(m_className, m_classNameHash, #varName, m_varNameHash);              \
			static const auto m_offset = offsetof(ThisClass, varName);                                                       \
																															 \
			uintptr_t pThisClass = ((uintptr_t)this - m_offset);                                                             \
																															 \
			NetworkStateChanged();                                                                                           \
			memcpy(                                                                                                          \
			reinterpret_cast<void*>(pThisClass + m_key.offset + extra_offset),												 \
			&val,																											 \
			sizeof(type)																									 \
			);                                                                                                               \
		}																													 \
		void NetworkStateChanged()                                                                                           \
		{                                                                                                                    \
			static const auto m_key = schema::GetOffset(m_className, m_classNameHash, #varName, m_varNameHash);				 \
			static const auto m_chain = schema::FindChainOffset(m_className, m_classNameHash);								 \
			static const auto m_offset = offsetof(ThisClass, varName);														 \
																															 \
			uintptr_t pThisClass = ((uintptr_t)this - m_offset);                                                             \
                                                                                                                             \
			if (m_chain != 0 && m_key.networked)                                                                             \
			{                                                                                                                \
				ChainNetworkStateChanged(pThisClass + m_chain, m_key.offset + extra_offset);								 \
			}                                                                                                                \
			else if (m_key.networked)                                                                                        \
			{                                                                                                                \
				if (!m_networkStateChangedOffset)                                                                            \
					EntityNetworkStateChanged(pThisClass, m_key.offset + extra_offset);									     \
				else                                                                                                         \
					NetworkVarStateChanged(pThisClass, m_key.offset + extra_offset, m_networkStateChangedOffset);			 \
			}                                                                                                                \
		}                                                                                                                    \
		operator std::add_lvalue_reference_t<type>()                                                                         \
		{                                                                                                                    \
			return Get();                                                                                                    \
		}                                                                                                                    \
		std::add_lvalue_reference_t<type> operator()()                                                                       \
		{                                                                                                                    \
			return Get();                                                                                                    \
		}                                                                                                                    \
		std::add_lvalue_reference_t<type> operator->()                                                                       \
		{                                                                                                                    \
			return Get();                                                                                                    \
		}                                                                                                                    \
		template <typename T = type>                                                                                         \
		std::enable_if_t<schema_writable_v<T>, void>                                                                         \
		operator()(T val)                                                                                                    \
		{                                                                                                                    \
			Set(val);                                                                                                        \
		}																													 \
		template <typename T = type>                                                                                         \
		std::enable_if_t<schema_writable_v<T>, varName##_prop&>                                                              \
		operator=(T val)                                                                                                     \
		{                                                                                                                    \
			Set(val);                                                                                                        \
			return *this;                                                                                                    \
		}																													 \
	private:                                                                                                                 \
		/*Prevent accidentally copying this wrapper class instead of the underlying field*/                                  \
		varName##_prop(const varName##_prop&) = delete;                                                                      \
		static constexpr auto m_varNameHash = hash_32_fnv1a_const(#varName);                                                 \
	} varName;

#define SCHEMA_FIELD_POINTER_OFFSET(type, varName, extra_offset)                                                             \
	class varName##_prop                                                                                                     \
	{                                                                                                                        \
	public:                                                                                                                  \
		type* Get()                                                                                                          \
		{                                                                                                                    \
			static const auto m_key = schema::GetOffset(m_className, m_classNameHash, #varName, m_varNameHash);				 \
			static const auto m_offset = offsetof(ThisClass, varName);														 \
																															 \
			uintptr_t pThisClass = ((uintptr_t)this - m_offset);                                                             \
                                                                                                                             \
			return reinterpret_cast<std::add_pointer_t<type>>(pThisClass + m_key.offset + extra_offset);                     \
		}                                                                                                                    \
		void NetworkStateChanged() /*Call this after editing the field*/                                                     \
		{                                                                                                                    \
			static const auto m_key = schema::GetOffset(m_className, m_classNameHash, #varName, m_varNameHash);				 \
			static const auto m_chain = schema::FindChainOffset(m_className, m_classNameHash);								 \
			static const auto m_offset = offsetof(ThisClass, varName);														 \
																															 \
			uintptr_t pThisClass = ((uintptr_t)this - m_offset);                                                             \
                                                                                                                             \
			if (m_chain != 0 && m_key.networked)                                                                             \
			{                                                                                                                \
				ChainNetworkStateChanged(pThisClass + m_chain, m_key.offset + extra_offset);								 \
			}                                                                                                                \
			else if (m_key.networked)                                                                                        \
			{                                                                                                                \
				if (!m_networkStateChangedOffset)                                                                            \
					EntityNetworkStateChanged(pThisClass, m_key.offset + extra_offset);									     \
				else                                                                                                         \
					NetworkVarStateChanged(pThisClass, m_key.offset + extra_offset, m_networkStateChangedOffset);			 \
			}                                                                                                                \
		}                                                                                                                    \
		operator type*()                                                                                                     \
		{                                                                                                                    \
			return Get();                                                                                                    \
		}                                                                                                                    \
		type* operator()()                                                                                                   \
		{                                                                                                                    \
			return Get();                                                                                                    \
		}                                                                                                                    \
		type* operator->()                                                                                                   \
		{                                                                                                                    \
			return Get();                                                                                                    \
		}                                                                                                                    \
	private:                                                                                                                 \
		/*Prevent accidentally copying this wrapper class instead of the underlying field*/                                  \
		varName##_prop(const varName##_prop&) = delete;                                                                      \
		static constexpr auto m_varNameHash = hash_32_fnv1a_const(#varName);                                                 \
	} varName;

/**

* @brief Declares schema field (auto offset + network update).
*
* @note This macro generates a wrapper class that:
* * Resolves offset via schema
* * Provides Get/Set
* * Automatically updates network state
* * Use this when you want the member's value itself
    */
#define SCHEMA_FIELD(type, varName) \
	SCHEMA_FIELD_OFFSET(type, varName, 0)

/**

* @brief Declares pointer schema field.
* * Use this when you want a pointer to a member
  */
#define SCHEMA_FIELD_POINTER(type, varName) \
	SCHEMA_FIELD_POINTER_OFFSET(type, varName, 0)

#define SCHEMA_FIELD_OLD(type, className, propName)                                                    \
    std::add_lvalue_reference_t<type> propName()                                                       \
    {                                                                                                  \
        static const int32_t offset = schema::GetServerOffset(#className, #propName);                  \
        if(offset == -1)                                                                               \
            std::runtime_error("Failed to find " #propName " in " #className);                         \
        return *reinterpret_cast<std::add_pointer_t<type>>(reinterpret_cast<intptr_t>(this) + offset); \
    }

/* =========================
Schema class macros
========================= */

/**

* @brief Declares schema-enabled class.
* * If the class needs a specific offset for its NetworkStateChanged (like CEconItemView), use this and provide the offset
  */
#define DECLARE_SCHEMA_CLASS_BASE(ClassName, offset)								\
	private:																		\
		typedef ClassName ThisClass;												\
		static constexpr const char* m_className = #ClassName;						\
		static constexpr uint32_t m_classNameHash = hash_32_fnv1a_const(#ClassName);\
		static constexpr int m_networkStateChangedOffset = offset;					\
	public:
#define DECLARE_SCHEMA_CLASS(className) DECLARE_SCHEMA_CLASS_BASE(className, 0)
/**

* @brief Declares inline schema class (non-entity).
* * Use this for non-entity classes such as CCollisionProperty or CGlowProperty
* * The only difference is that their NetworkStateChanged function is index 1 on their vtable rather than being CEntityInstance::NetworkStateChanged
* * Though some classes like CGameRules will instead use their CNetworkVarChainer as a link back to the parent entity
  */
#define DECLARE_SCHEMA_CLASS_INLINE(className) DECLARE_SCHEMA_CLASS_BASE(className, 1)
