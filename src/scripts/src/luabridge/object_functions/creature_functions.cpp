
#include "LUAEngine.h"
#include "lua_creature.h"


LuaCreature::LuaCreature(Creature* creature) : CreatureAIScript(creature), m_binding(NULL) {}
LuaCreature::~LuaCreature() {}

void LuaCreature::OnCombatStart(Unit* mTarget)
{
	NULL_BINDING_CHECK
		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_ENTER_COMBAT]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_ENTER_COMBAT);
	push_unit(mTarget);
	lua_engine::ExecuteLuaFunction(3);

	RELEASE_LOCK
}

void LuaCreature::OnCombatStop(Unit* mTarget)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_LEAVE_COMBAT]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_LEAVE_COMBAT);
	push_unit(mTarget);
	lua_engine::ExecuteLuaFunction(3);

	RELEASE_LOCK
}

void LuaCreature::OnTargetDied(Unit* mTarget)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_TARGET_DIED]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_TARGET_DIED);
	push_unit(mTarget);
	lua_engine::ExecuteLuaFunction(3);

	RELEASE_LOCK
}

void LuaCreature::OnDied(Unit *mKiller)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_DIED]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_DIED);
	push_unit(mKiller);
	lua_engine::ExecuteLuaFunction(3);

	RELEASE_LOCK
}

void LuaCreature::OnTargetParried(Unit* mTarget)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_TARGET_PARRIED]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_TARGET_PARRIED);
	push_unit(mTarget);
	lua_engine::ExecuteLuaFunction(3);

	RELEASE_LOCK
}

void LuaCreature::OnTargetDodged(Unit* mTarget)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_TARGET_DODGED]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_TARGET_DODGED);
	push_unit(mTarget);
	lua_engine::ExecuteLuaFunction(3);

	RELEASE_LOCK
}

void LuaCreature::OnTargetBlocked(Unit* mTarget, int32 iAmount)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_TARGET_BLOCKED]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_TARGET_BLOCKED);
	push_unit(mTarget);
	push_int(iAmount);
	lua_engine::ExecuteLuaFunction(4);

	RELEASE_LOCK
}

void LuaCreature::OnTargetCritHit(Unit* mTarget, int32 fAmount)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_TARGET_CRIT_HIT]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_TARGET_CRIT_HIT);
	push_unit(mTarget);
	push_int(fAmount);
	lua_engine::ExecuteLuaFunction(4);
	RELEASE_LOCK
}

void LuaCreature:: OnParried(Unit* mTarget)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_PARRY]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_PARRY);
	push_unit(mTarget);
	lua_engine::ExecuteLuaFunction(3);

	RELEASE_LOCK
}

void LuaCreature::OnDodged(Unit* mTarget)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_DODGED]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_DODGED);
	push_unit(mTarget);
	lua_engine::ExecuteLuaFunction(3);
	RELEASE_LOCK
}

void LuaCreature::OnBlocked(Unit* mTarget, int32 iAmount)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_BLOCKED]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_BLOCKED);
	push_unit(mTarget);
	push_int(iAmount);
	lua_engine::ExecuteLuaFunction(4);
	RELEASE_LOCK
}

void LuaCreature::OnCritHit(Unit* mTarget, int32 fAmount)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_CRIT_HIT]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_CRIT_HIT);
	push_unit(mTarget);
	push_int(fAmount);
	lua_engine::ExecuteLuaFunction(4);
	RELEASE_LOCK
}

void LuaCreature::OnHit(Unit* mTarget, float fAmount)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_HIT]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_HIT);
	push_unit(mTarget);
	push_float(fAmount);
	lua_engine::ExecuteLuaFunction(4);

	RELEASE_LOCK
}

void LuaCreature::OnAssistTargetDied(Unit* mAssistTarget)
{

	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_ASSIST_TARGET_DIED]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_ASSIST_TARGET_DIED);
	push_unit(mAssistTarget);
	lua_engine::ExecuteLuaFunction(3);

	RELEASE_LOCK
}

void LuaCreature::OnFear(Unit* mFeared, uint32 iSpellId)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_FEAR]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_FEAR);
	push_unit(mFeared);
	push_int(iSpellId);
	lua_engine::ExecuteLuaFunction(4);

	RELEASE_LOCK
}

void LuaCreature::OnFlee(Unit* mFlee)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_FLEE]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_FLEE);
	push_unit(mFlee);
	lua_engine::ExecuteLuaFunction(3);

	RELEASE_LOCK
}

void LuaCreature::OnCallForHelp()
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_CALL_FOR_HELP]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_CALL_FOR_HELP);
	lua_engine::ExecuteLuaFunction(2);

	RELEASE_LOCK
}

void LuaCreature::OnLoad()
{
	NULL_BINDING_CHECK

	lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_LOAD]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_LOAD);
	lua_engine::ExecuteLuaFunction(2);

	RELEASE_LOCK
	/*uint32 iid = _unit->GetInstanceID();
	if (_unit->GetMapMgr() == NULL || _unit->GetMapMgr()->GetMapInfo()->type == INSTANCE_NULL)
		iid = 0;
	OnLoadInfo.push_back(_unit->GetMapId());
	OnLoadInfo.push_back(iid);
	OnLoadInfo.push_back(GET_LOWGUID_PART(_unit->GetGUID()));*/
}

void LuaCreature::OnReachWP(uint32 iWaypointId, bool bForwards)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_REACH_WP]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_REACH_WP);
	push_int(iWaypointId);
	push_bool(bForwards);
	lua_engine::ExecuteLuaFunction(4);

	RELEASE_LOCK
}

void LuaCreature::OnLootTaken(Player* pPlayer, ItemPrototype *pItemPrototype)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_LOOT_TAKEN]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_LOOT_TAKEN);
	push_player(pPlayer);
	push_int(pItemPrototype->ItemId);
	lua_engine::ExecuteLuaFunction(4);
	RELEASE_LOCK
}

void LuaCreature::AIUpdate()
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_AIUPDATE]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_AIUPDATE);
	lua_engine::ExecuteLuaFunction(2);

	RELEASE_LOCK
}

void LuaCreature::OnEmote(Player * pPlayer, EmoteType Emote)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_EMOTE]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_EMOTE);
	push_player(pPlayer);
	push_int( (int)Emote);
	lua_engine::ExecuteLuaFunction(4);

	RELEASE_LOCK
}

void LuaCreature::OnDamageTaken(Unit* mAttacker, uint32 fAmount)
{
	NULL_BINDING_CHECK

		lua_engine::BeginLuaFunctionCall(m_binding->refs[CREATURE_EVENT_ON_DAMAGE_TAKEN]);
	push_creature(_unit);
	push_int(CREATURE_EVENT_ON_DAMAGE_TAKEN);
	push_unit(mAttacker);
	push_int(fAmount);
	lua_engine::ExecuteLuaFunction(4);
	RELEASE_LOCK
}

void LuaCreature::Destroy()
{
	PLUA_INSTANCE li_ = lua_instance.get();
	{
		li::CreatureInterfaceMap::iterator it;
		li::CreatureInterfaceMap::iterator itr = li_->m_creatureInterfaceMap.find(_unit->GetEntry() ), itend = li_->m_creatureInterfaceMap.upper_bound(_unit->GetEntry() );
		for(;itr != itend;)
		{
			it = itr++;
			if(it->second != NULL && it->second == this)
				li_->m_creatureInterfaceMap.erase(it);
		}
	}
	{
		//Function Ref clean up
		li::ObjectFRefMap::iterator it, itr = li_->m_creatureFRefs.find(_unit->GetLowGUID() );
		li::ObjectFRefMap::iterator itend = li_->m_creatureFRefs.upper_bound(_unit->GetLowGUID() );
		while(itr != itend)
		{
			it = itr++;
			sEventMgr.RemoveEvents(_unit, itr->second->head_node->val.obj_ref+EVENT_LUA_CREATURE_EVENTS);
			cleanup_varparam(it->second, li_->lu );

		}
	}
	delete this;
}

namespace lua_engine
{
	CreatureAIScript * createluacreature(Creature * src)
	{
		LuaCreature * script = NULL;
		PLUA_INSTANCE ref = lua_instance.get();
		if(src != NULL)
		{
			uint32 id = src->GetEntry();
			li::ObjectBindingMap::iterator itr = ref->m_unitBinding.find(id);
			PObjectBinding bind = (itr != ref->m_unitBinding.end() ) ? itr->second : NULL;
			if( bind != NULL)
			{
				script = new LuaCreature(src);
				script->m_binding = bind;
				ref->m_creatureInterfaceMap.insert( make_pair(id, script) );
			}
		}
		return script;
	}
	void bindCreatureMethods(luabridge::module & m )
	{
#define prop(name) .property_ro(#name, &CreatureProto::name)
		m	.class_<CreatureProto>("CreatureProto")
			prop(Id)
			prop(MinLevel)
			prop(MaxLevel)
			prop(Faction)
			prop(MinHealth)
			prop(MaxHealth)
			prop(Mana)
			prop(NPCFLags)
			prop(MinDamage)
			prop(MaxDamage)
			prop(boss)
			prop(walk_speed)
			prop(run_speed)
			prop(fly_speed)
			prop(isTrainingDummy)
			prop(guardtype)
			prop(summonguard);
#undef prop
#define prop(name) .property_ro(#name, &CreatureInfo::name)
		m	.class_<CreatureInfo>("CreatureInfo")
			prop(Id)
			prop(Name)
			prop(SubName)
			prop(Type)
			prop(Family)
			prop(Rank);
#undef prop
		m	.class_<CreatureAIScript>("CreatureAIScript")
			.method("RegisterAIUpdateEvent", &CreatureAIScript::RegisterAIUpdateEvent)
			.method("ModifyAIUpdateEvent", &CreatureAIScript::ModifyAIUpdateEvent)
			.method("RemoveAIUpdateEvent", &CreatureAIScript::RemoveAIUpdateEvent);

#define bind(name) .method(#name, &Creature::name)
		m	.subclass<Creature, Unit>("Creature")
			bind(IsVehicle)
			//bind(isGuard)
			//bind(isNeutralGuard)
			.method("RemoveFromWorld", (void (Creature::*)(bool) )&Creature::RemoveFromWorld)
			bind(HasItems)
			bind(GetProto)
			bind(GetItemIdBySlot)
			bind(GetItemAmountBySlot)
			bind(GetSlotByItemId)
			bind(GetItemAmountByItemId)
			bind(HasQuests)
			bind(HasQuest)
			bind(AddQuest)
			bind(DeleteQuest)
			bind(FindQuest)
			bind(GetQuestRelation)
			bind(NumOfQuests)
			bind(isVendor)
			bind(isTrainer)
			bind(isClass)
			bind(isProf)
			bind(isQuestGiver)
			bind(isGossip)
			bind(isTaxi)
			bind(isCharterGiver)
			bind(isGuildBank)
			bind(isBattleMaster)
			bind(isBanker)
			bind(isInnkeeper)
			bind(isSpiritHealer)
			bind(isTabardDesigner)
			bind(isAuctioner)
			bind(isStableMaster)
			bind(isArmorer)
			.property_rw("canregeneratehp", &Creature::m_canRegenerateHP)
			bind(CanSee)
			.property_ro("isSkinned", &Creature::Skinned)
			bind(GetSQL_id)
			bind(GetTotemSlot)
			bind(GetGroup)
			bind(IsPickPocketed)
			bind(GetCreatureInfo)
			bind(SetCreatureProto)
			bind(IsTotem)
			bind(IsExotic)
			bind(GetScript)
			.method("IsCritter", &Creature::isCritter)
			.method("IsTrainingDummy", &Creature::isTrainingDummy)
			.method("Despawn", &Creature::Despawn)	
			.property_rw("m_noRespawn", &Creature::m_noRespawn)
			.property_ro("m_escorter", &Creature::m_escorter)
			.method("RegisterEvent", (void (Creature::*)(lua_function,uint32,uint32,variadic_parameter*,lua_stack) )&lua_creature::RegisterScriptEngineFunction)
			.method("RemoveEvents", (void (Creature::*)() )&lua_creature::RemoveScriptEngineEvents)
			.method("GetRandomEnemy", (Unit* (Creature::*)() )&lua_creature::GetRandomEnemy)
			.method("GetRandomFriend", (Unit*(Creature::*)() )&lua_creature::GetRandomFriend)
			.method("GetRandomPlayer", (Player* (Creature::*)(int) )&lua_creature::GetRandomPlayer)
			.method("GetClosestFriend", (Unit*(Creature::*)() )&lua_creature::GetClosestFriend)
			.method("GetClosestEnemy", (Unit* (Creature::*)() )&lua_creature::GetClosestEnemy)
			.method("GetClosestPlayer", (Unit* (Creature::*)() )&lua_creature::GetClosestPlayer)
			.method("GetSpawnId", &Creature::GetSQL_id);
#undef bind
#define BIND(name) .method(#name, &AIInterface::name)
			m.	class_<AIInterface>("AIInterface")
				BIND(GetPetOwner)
				BIND(SetPetOwner)
				.method("SetUnitToFollow", (void(AIInterface::*)(Unit*))&AIInterface::SetUnitToFollow)
				BIND(getUnitToFollow)
				BIND(SetFollowDistance)
				BIND(SetUnitToFollowAngle)
				BIND(getUnitToFear)
				.method("SetUnitToFear", (void(AIInterface::*)(Unit*))&AIInterface::SetUnitToFear)
				BIND(getSoullinkedWith)
				BIND(GetIsSoulLinked)
				BIND(SetSoulLinkedWith)
				BIND(getAIState)
				BIND(SetAIState)
				BIND(addSpellToList)
				BIND(SetNextSpell)
				BIND(MoveTo)
				//BIND(calcMoveTimeToLocation)
				BIND(StopMovement)
				BIND(hasWaypoints)
				//BIND(Movement_allowmovement)
				.property_rw("canmove", &AIInterface::m_canMove)
				.property_rw("moveRun", &AIInterface::m_moveRun)
				.property_rw("moveFly", &AIInterface::m_moveFly)
				//BIND(Movement_canmove)
				//BIND(Movement_isflying)
				//BIND(calcAggroRange)
				//BIND(calcCombatRange)
				BIND(getNextTarget)
				.method("setNextTarget", (void(AIInterface::*)(Unit*) )&AIInterface::setNextTarget)
				BIND(AttackReaction)
				BIND(HealReaction)
				.property_rw("disable_combat", &AIInterface::disable_combat)
				.property_rw("disable_melee", &AIInterface::disable_melee)
				.property_rw("disable_spell", &AIInterface::disable_spell)
				.property_rw("disable_targeting", &AIInterface::disable_targeting)
				.property_rw("m_canRangedAttack", &AIInterface::m_canRangedAttack)
				.property_rw("m_canCallForHelp", &AIInterface::m_canCallForHelp)
				.property_rw("m_CallForHelpHealth", &AIInterface::m_CallForHelpHealth)
				.property_rw("m_canFlee", &AIInterface::m_canFlee)
				.property_rw("m_FleeHealth", &AIInterface::m_FleeHealth)
				.property_rw("m_FleeDuration", &AIInterface::m_FleeDuration)
				BIND(ClearHateList)
				BIND(WipeHateList)
				BIND(WipeTargetList)
				BIND(RemoveThreatByPtr)
				BIND(modThreatByPtr)
				BIND(getThreatByPtr)
				BIND(GetMostHated)
				BIND(GetSecondHated)
				BIND(taunt)
				BIND(getTauntedBy)
				BIND(GetIsTaunted)
				BIND(getSoullinkedWith)
				BIND(SetSoulLinkedWith)
				BIND(GetIsSoulLinked)
				BIND(getOutOfCombatRange)
				BIND(setOutOfCombatRange)
				BIND(MoveTo)
				BIND(getCurrentWaypoint)
				BIND(changeWayPointID)
				BIND(getWayPoint)
				BIND(deleteWayPoint)
				BIND(deleteWaypoints)
				BIND(setMoveType)
				BIND(getMoveType)
				BIND(setMoveRunFlag)
				BIND(getMoveRunFlag)
				BIND(setWaypointToMove)
				BIND(IsFlying)
				BIND(getCurrentAgent)
				BIND(setCurrentAgent)
				BIND(SetAllowedToEnterCombat)
				BIND(GetAllowedToEnterCombat)
				.method("GetAITargetsCount", &AIInterface::getAITargetsCount);
#undef BIND

			//waypoint struct
			m	.class_<WayPoint>("WayPoint")
				.constructor<void (*)() >()
				.property_rw("id", &WayPoint::id)
				.property_rw("x", &WayPoint::x)
				.property_rw("y", &WayPoint::y)
				.property_rw("z", &WayPoint::z)
				.property_rw("o", &WayPoint::o)
				.property_rw("waittime", &WayPoint::waittime)
				.property_rw("flags", &WayPoint::flags);
				
	}
}