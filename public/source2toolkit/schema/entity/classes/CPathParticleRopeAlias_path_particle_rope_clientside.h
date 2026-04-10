#pragma once
#include "CBaseEntity.h"
#include "igameevents.h"
#include "ehandle.h"
#include "entityhandle.h"
#include "vector.h"
#include "utlsymbol.h"
#include "utlsymbollarge.h"
#include "utlstring.h"
#include "utlstringtoken.h"
#include "source2toolkit/IToolkitTypes.h"
#include "source2toolkit/schema/entityio.h"
#include "source2toolkit/schema/schema.h"
#include <cstdint>

#include "CPathParticleRope.h"

class CPathParticleRopeAlias_path_particle_rope_clientside : public CPathParticleRope
{
public:
    DECLARE_SCHEMA_CLASS(CPathParticleRopeAlias_path_particle_rope_clientside);


public:
    static CPathParticleRopeAlias_path_particle_rope_clientside* New(const char* className)
    {
        return CBaseEntity::New<CPathParticleRopeAlias_path_particle_rope_clientside>(className);
    }

    static CPathParticleRopeAlias_path_particle_rope_clientside* FromIndex(int iIndex)
    {
        return CBaseEntity::FromIndex<CPathParticleRopeAlias_path_particle_rope_clientside>(iIndex);
    }

    static CPathParticleRopeAlias_path_particle_rope_clientside* FromIndex(CEntityIndex index)
    {
        return FromIndex(index.Get());
    }
};
