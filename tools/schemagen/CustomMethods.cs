namespace Source2Toolkit.SchemaGen;

public static class CustomMethods
{
    public static readonly Dictionary<string, List<string>> ManualMethods = new()
    {
        ["CBaseEntity"] = new()
        {
            "/// <summary>Creates entity by classname.</summary>",
            "static CBaseEntity* CreateEntityByName(const char* pszClassName);",

            "/// <summary>Create entity by classname.</summary>",
            "template<typename T>\n    static T* New(const char* pszClassName)\n    {    \n        return reinterpret_cast<T*>(CreateEntityByName(pszClassName));\n    }",

            "/// <summary>Get entity by index.</summary>",
            "template<typename T>\n    static T* FromIndex(int iIndex)\n    {    \n        return reinterpret_cast<T*>(GetEntitySystem()->GetEntityInstance(CEntityIndex(iIndex)));\n    }",

            "/// <summary>Get entity by entity index.</summary>",
            "template<typename T>\n    static T* FromIndex(CEntityIndex index)\n    {    \n        return FromIndex<T>(index.Get());\n    }",

            "/// <summary>Accepts entity input.</summary>",
            "void AcceptInput(const char* pszInput, CEntityInstance* pActivator = nullptr, CEntityInstance* pCaller = nullptr, const char* pszValue = \"\");",

            "/// <summary>Add delayed entity IO event.</summary>",
            "void AddEntityIOEvent(const char* pszInput, CEntityInstance* pActivator = nullptr, CEntityInstance* pCaller = nullptr, const char* pszValue = \"\", float flDelay = 0.0f);",

            "/// <summary>Add signle entity IO listener.</summary>",
            "CEntityIOListenerHandle* AddSingleEntityIOListener(const char* pszOutput, std::function<Action(const char*,CEntityInstance*, CEntityInstance*, float, Mode)> callback, Mode mode);",

            "/// <summary>Get absolute origin.</summary>",
            "Vector GetAbsOrigin();",

            "/// <summary>Get local rotation.</summary>",
            "QAngle GetAngRotation();",

            "/// <summary>Get absolute rotation.</summary>",
            "QAngle GetAbsRotation();",

            "/// <summary>Get absolute velocity.</summary>",
            "Vector GetAbsVelocity();",

            "/// <summary>Set absolute origin.</summary>",
            "void SetAbsOrigin(Vector vecOrigin);",

            "/// <summary>Set absolute rotation.</summary>",
            "void SetAbsRotation(QAngle angAbsRotation);",

            "/// <summary>Set local rotation.</summary>",
            "void SetAngRotation(QAngle angRotation);",

            "/// <summary>Set absolute velocity.</summary>",
            "void SetAbsVelocity(Vector vecVelocity);",

            "/// <summary>Set base velocity.</summary>",
            "void SetBaseVelocity(Vector vecVelocity);",

            "/// <summary>Get entity VData.</summary>",
            "CEntitySubclassVDataBase* GetVData();",

            "/// <summary>Spawn entity.</summary>",
            "void DispatchSpawn(CEntityKeyValues* pEntityKeyValues = nullptr);",

            "/// <summary>Teleport entity.</summary>",
            "void Teleport(const Vector* pPosition, const QAngle* pAngles, const Vector* pVelocity);",

            "/// <summary>Set move type.</summary>",
            "void SetMoveType(MoveType_t nMoveType);",

            "/// <summary>Get collision group.</summary>",
            "uint8 GetCollisionGroup();",

            "/// <summary>Set collision group.</summary>",
            "void SetCollisionGroup(uint8 nCollisionGroup);",

            "/// <summary>Notify collision rules changed.</summary>",
            "void CollisionRulesChanged();",

            "/// <summary>Get entity index.</summary>",
            "int GetIndex();",

            "/// <summary>Get entity handle.</summary>",
            "CHandle<CBaseEntity> GetHandle();",

            "/// <summary>Get entity name.</summary>",
            "const char* GetName() const;"
        },


        ["CBaseModelEntity"] = new()
        {
            "/// <summary>Get model name.</summary>",
            "CUtlSymbolLarge GetModelName();",

            "/// <summary>Get eye position.</summary>",
            "Vector GetEyePosition();",

            "/// <summary>Set entity model.</summary>",
            "void SetModel(const char* pszModel);"
        },


        ["CBasePlayerController"] = new()
        {
            "/// <summary>Set pawn for controller.</summary>",
            "void SetPawn(CBasePlayerPawn* pPawn);"
        },


        ["CBasePlayerPawn"] = new()
        {
            "/// <summary>Force suicide.</summary>",
            "void CommitSuicide(bool bExplode, bool bForce);",

            "/// <summary>Remove weapon from player.</summary>",
            "void RemovePlayerItem(CBasePlayerWeapon* pWeapon);"
        },


        ["CBasePlayerWeapon"] = new()
        {
            "/// <summary>Get weapon VData.</summary>",
            "CCSWeaponBaseVData* GetWeaponVData();",

            "/// <summary>Get weapon classname.</summary>",
            "const char* GetWeaponClassname();"
        },


        ["CCSGameRules"] = new()
        {
            "/// <summary>Terminate round.</summary>",
            "void TerminateRound(float flDelay, int32_t eRoundEndReason);",

            "/// <summary>Find entity player is aiming at.</summary>",
            "CBaseEntity* FindPickerEntity(CBasePlayerController* pPlayer);",

            "/// <summary>Get aim target.</summary>",
            "CCSPlayerController* GetClientAimTarget(CCSPlayerController* pPlayer);",
        },


        ["CCSPlayerController"] = new()
        {
            "/// <summary>Get controller from pawn.</summary>",
            "static CCSPlayerController* FromPawn(CCSPlayerPawn* pPawn);",

            "/// <summary>Get controller from slot.</summary>",
            "static CCSPlayerController* FromSlot(int iSlot);",

            "/// <summary>Get controller from slot.</summary>",
            "static CCSPlayerController* FromSlot(CPlayerSlot slot);",

            "/// <summary>Get controller from user id.</summary>",
            "static CCSPlayerController* FromUserId(int iUserId);",

            "/// <summary>Get controller from user id.</summary>",
            "static CCSPlayerController* FromUserId(CPlayerUserId userId);",

            "/// <summary>Get controller from steam id.</summary>",
            "static CCSPlayerController* FromSteamId(uint64 uSteamId);",

            "/// <summary>Get controller from steam id.</summary>",
            "static CCSPlayerController* FromSteamId(CSteamID steamId);",

            "/// <summary>Print to console.</summary>",
            "void PrintToConsole(const char* pszMessage);",

            "/// <summary>Print to chat.</summary>",
            "void PrintToChat(const char* pszMessage);",

            "/// <summary>Print to center.</summary>",
            "void PrintToCenter(const char* pszMessage);",

            "/// <summary>Print alert.</summary>",
            "void PrintToCenterAlert(const char* pszMessage);",

            "/// <summary>Print to center in HTML.</summary>",
            "void PrintToCenterHtml(const char* pszMessage, int iDuration = 5);",

            "/// <summary>Respawn player.</summary>",
            "void Respawn();",

            "/// <summary>Switch team without killing.</summary>",
            "void SwitchTeam(int nTeam);",

            "/// <summary>Change team like jointeam.</summary>",
            "void ChangeTeam(int nTeam);",

            "/// <summary>Is bot.</summary>",
            "bool IsBot();",

            "/// <summary>Disconnect player.</summary>",
            "void Disconnect(ENetworkDisconnectionReason eReason);",

            "/// <summary>Execute client command.</summary>",
            "void ExecuteClientCommand(const char* pszCommand);",

            "/// <summary>Execute command from server.</summary>",
            "void ExecuteClientCommandFromServer(const char* pszCommand);",

            "/// <summary>Get pawn.</summary>",
            "CCSPlayerPawn* GetPawn();",

            "/// <summary>Get player pawn.</summary>",
            "CCSPlayerPawn* GetPlayerPawn();",

            "/// <summary>Get observer pawn.</summary>",
            "CCSObserverPawn* GetObserverPawn();",

            "/// <summary>Get player index.</summary>",
            "CEntityIndex GetPlayerIndex();",

            "/// <summary>Get slot.</summary>",
            "int GetSlot();",

            "/// <summary>Get player slot.</summary>",
            "CPlayerSlot GetPlayerSlot();",

            "/// <summary>Get steamid.</summary>",
            "int GetUserID();",

            "/// <summary>Get player userid.</summary>",
            "CPlayerUserId GetPlayerUserID();",

            "/// <summary>Get steamid.</summary>",
            "uint64 GetSteamID();",

            "/// <summary>Get player steamid.</summary>",
            "CSteamID GetPlayerSteamID();",

            "/// <summary>Get player name.</summary>",
            "const char* GetPlayerName();",

            "/// <summary>Get IP address.</summary>",
            "const char* GetIpAddress();",

            "/// <summary>Replicate convar.</summary>",
            "void ReplicateConVar(const char* pszConVar, const char* pszValue);",

            "/// <summary>Fires gameEvent to client's legacy listener.</summary>",
            "void FireEventToClient(IGameEvent* pEvent);",
        },


        ["CCSPlayerPawn"] = new()
        {
            "/// <summary>Get controller.</summary>",
            "CCSPlayerController* GetController();",

            "/// <summary>Get default controller.</summary>",
            "CCSPlayerController* GetDefaultController();",

            "/// <summary>Get original controller.</summary>",
            "CCSPlayerController* GetOriginalController();",
        },


        ["CCSPlayer_ItemServices"] = new()
        {
            "/// <summary>Drop active weapon.</summary>",
            "void DropActivePlayerWeapon(CBasePlayerWeapon* pActiveWeapon);",

            "/// <summary>Remove all weapons.</summary>",
            "void RemoveWeapons();",

            "/// <summary>Give item.</summary>",
            "CBasePlayerWeapon* GiveNamedItem(const char* pszItem);"
        },
    };
}