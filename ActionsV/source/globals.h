#pragma once
#include <types.h>

#define LOOP(i, n) for(int i = 0; i < n; ++i)

typedef struct { int R, G, B, A; } RGBA;

//Globals
extern Player player;
extern Ped playerPed;

//Constants
constexpr Hash WEAPON_UNARMED = -1569615261;

//Ped move blend ratios
constexpr float PEDMOVEBLENDRATIO_STILL = 0.0f;
constexpr float PEDMOVEBLENDRATIO_WALK = 1.0f;
constexpr float PEDMOVEBLENDRATIO_RUN = 2.0f;
constexpr float PEDMOVEBLENDRATIO_SPRINT = 3.0f;

//Animation blend in/out ratios
constexpr float WALK_BLEND_IN = 1.5f;			// 20frms
constexpr float WALK_BLEND_OUT = -1.5f;			// 20frms
constexpr float REALLY_SLOW_BLEND_IN = 2.0f;	// 15frms
constexpr float REALLY_SLOW_BLEND_OUT = -2.0f;	// 15frms
constexpr float SLOW_BLEND_IN = 4.0f;			// 8frms
constexpr float SLOW_BLEND_OUT = -4.0f;			// 8frms
constexpr float NORMAL_BLEND_IN = 8.0f;			// 4frms
constexpr float NORMAL_BLEND_OUT = -8.0f;		// 4frms
constexpr float FAST_BLEND_IN = 16.0f;			// 2frms
constexpr float FAST_BLEND_OUT = -16.0f;		// 2frms
constexpr float INSTANT_BLEND_IN = 1000.0f;		// 0frms
constexpr float INSTANT_BLEND_OUT = -1000.0f;	// 0frms

//Enums
enum HUDComponent {
	HUD_WANTED_STARS = 1,
	HUD_WEAPON_ICON,
	HUD_CASH,
	HUD_MP_CASH,
	HUD_MP_MESSAGE,
	HUD_VEHICLE_NAME,
	HUD_AREA_NAME,
	HUD_DISTRICT_NAME,
	HUD_STREET_NAME,
	HUD_HELP_TEXT,
	HUD_FLOATING_HELP_TEXT_1,
	HUD_FLOATING_HELP_TEXT_2,
	HUD_CASH_CHANGE,
	HUD_RETICLE,
	HUD_SUBTITLE_TEXT,
	HUD_RADIO_STATIONS,
	HUD_SAVING_GAME,
	HUD_FEED,
	HUD_WEAPON_WHEEL,
	HUD_WEAPON_WHEEL_STATS
};

enum TextFonts {
	FONT_STANDARD = 0,
	FONT_CURSIVE,
	FONT_ROCKSTAR_TAG,
	FONT_LEADERBOARD,
	FONT_CONDENSED,
	FONT_STYLE_FIXED_WIDTH_NUMBERS,
	FONT_CONDENSED_NOT_GAMERNAME,
	FONT_STYLE_PRICEDOWN,
	FONT_STYLE_TAXI
};

enum DropStyle {
	DROPSTYLE_NONE = 0,
	DROPSTYLE_ALL = 1,
	DROPSTYLE_OUTLINEONLY = 2,
	DROPSTYLE_DROPSHADOWONLY = 3
};

enum GFXDrawOrder {
	GFX_ORDER_BEFORE_HUD_PRIORITY_LOW = 0,
	GFX_ORDER_BEFORE_HUD,  // standard
	GFX_ORDER_BEFORE_HUD_PRIORITY_HIGH,

	GFX_ORDER_AFTER_HUD_PRIORITY_LOW,
	GFX_ORDER_AFTER_HUD,  // standard
	GFX_ORDER_AFTER_HUD_PRIORITY_HIGH,

	GFX_ORDER_AFTER_FADE_PRIORITY_LOW,
	GFX_ORDER_AFTER_FADE,  // standard
	GFX_ORDER_AFTER_FADE_PRIORITY_HIGH
};

enum StandardTextType {
	TEXTTYPE_TS_TITLE = 0,
	TEXTTYPE_TS_TITLESMALL,
	//  TEXTTYPE_TS_STANDARDTINY,
	TEXTTYPE_TS_STANDARDSMALL,
	TEXTTYPE_TS_STANDARDMEDIUM,
	TEXTTYPE_TS_LBD,
	TEXTTYPE_TS_LBD_PLYR_NAME,

	TEXTTYPE_TS_TIMER_PLYR_NAME,
	//  TEXTTYPE_TS_STANDARDBIG,
	//  TEXTTYPE_TS_STANDARDHUGE,
	//  TEXTTYPE_TS_EXTRA1,

	TEXTTYPE_TS_TITLEHUD,
	TEXTTYPE_TS_HUDNUMBER,

	TEXTTYPE_TS_UI_TIMERNUMBER_THREESETS,
	TEXTTYPE_TS_UI_TIMERNUMBER_TWOSETS,
	TEXTTYPE_TS_UI_SINGLE_NUMBER,
	TEXTTYPE_TS_UI_DASHSINGLE,
	TEXTTYPE_TS_UI_DASHDOUBLE,
	TEXTTYPE_TS_UI_DASHTRIPLE,
	TEXTTYPE_TS_UI_POSITION_SYMBOL,
	TEXTTYPE_TS_UI_SCORE,
	TEXTTYPE_TS_UI_SCORE_SMALL,
	TEXTTYPE_TS_UI_SCORE_SMALL_NON_ROMANIC,
	TEXTTYPE_TS_UI_AMPM,
	TEXTTYPE_TS_UI_METER_BIG_TITLE,
	TEXTTYPE_TS_UI_METER_BIG_TITLE_WAVE,

	TEXTTYPE_TS_STANDARDMEDIUMHUD,
	TEXTTYPE_TS_STANDARDSMALLHUD,

	TEXTTYPE_TS_MINIGAME_MENU_TITLE,
	TEXTTYPE_TS_MINIGAME_MENU_PRIMARY,
	TEXTTYPE_TS_MINIGAME_MENU_SECONDARY,
	TEXTTYPE_TS_MINIGAME_MENU_TERTIARY,
	TEXTTYPE_TS_MINIGAME_MENU_NOTIFICATION,
	TEXTTYPE_TS_MINIGAME_MENU_GAMERTAG
};

struct TextStyle {
	TextFonts aFont;
	float XScale, YScale;
	RGBA colour;
	DropStyle drop;
	float WrapStartX, WrapEndX;
	StandardTextType aTextType;
};

struct TextPlacement {
	float x;
	float y;
};

struct ScaleformButton {
	int	iButtonSlotControl = NULL;
	int	iButtonSlotInput = NULL;
	char* sText = "";
};

struct ScaleformInstructionalButtons {
	bool bInitialised = false;
	ScaleformButton Buttons[12];
	int ButtonCount = 0;
};

enum CombatAttribute {
	CA_INVALID = -1,
	CA_USE_COVER = 0,
	CA_USE_VEHICLE = 1,
	CA_DO_DRIVEBYS = 2,
	CA_LEAVE_VEHICLES = 3,
	CA_CAN_USE_DYNAMIC_STRAFE_DECISIONS = 4,
	CA_ALWAYS_FIGHT = 5,
	CA_FLEE_WHILST_IN_VEHICLE = 6,
	CA_JUST_FOLLOW_VEHICLE = 7,
	CA_PLAY_REACTION_ANIMS = 8,
	CA_WILL_SCAN_FOR_DEAD_PEDS = 9,
	CA_IS_A_GUARD = 10,
	CA_JUST_SEEK_COVER = 11,
	CA_BLIND_FIRE_IN_COVER = 12,
	CA_AGGRESSIVE = 13,
	CA_CAN_INVESTIGATE = 14,
	CA_CAN_USE_RADIO = 15,
	CA_CAN_CAPTURE_ENEMY_PEDS = 16,
	CA_ALWAYS_FLEE = 17,
	CA_CAN_TAUNT_IN_VEHICLE = 20,
	CA_CAN_CHASE_TARGET_ON_FOOT = 21,
	CA_WILL_DRAG_INJURED_PEDS_TO_SAFETY = 22,
	CA_REQUIRES_LOS_TO_SHOOT = 23,
	CA_USE_PROXIMITY_FIRING_RATE = 24,
	CA_DISABLE_SECONDARY_TARGET = 25,
	CA_DISABLE_ENTRY_REACTIONS = 26,
	CA_PERFECT_ACCURACY = 27,
	CA_CAN_USE_FRUSTRATED_ADVANCE = 28,
	CA_MOVE_TO_LOCATION_BEFORE_COVER_SEARCH = 29,
	CA_CAN_SHOOT_WITHOUT_LOS = 30,
	CA_MAINTAIN_MIN_DISTANCE_TO_TARGET = 31,
	CA_CAN_USE_PEEKING_VARIATIONS = 34,
	CA_DISABLE_PINNED_DOWN = 35,
	CA_DISABLE_PIN_DOWN_OTHERS = 36,
	CA_OPEN_COMBAT_WHEN_DEFENSIVE_AREA_IS_REACHED = 37,
	CA_DISABLE_BULLET_REACTIONS = 38,
	CA_CAN_BUST = 39,
	CA_IGNORED_BY_OTHER_PEDS_WHEN_WANTED = 40,
	CA_CAN_COMMANDEER_VEHICLES = 41,
	CA_CAN_FLANK = 42,
	CA_SWITCH_TO_ADVANCE_IF_CANT_FIND_COVER = 43,
	CA_SWITCH_TO_DEFENSIVE_IF_IN_COVER = 44,
	CA_CLEAR_PRIMARY_DEFENSIVE_AREA_WHEN_REACHED = 45,
	CA_CAN_FIGHT_ARMED_PEDS_WHEN_NOT_ARMED = 46,
	CA_ENABLE_TACTICAL_POINTS_WHEN_DEFENSIVE = 47,
	CA_DISABLE_COVER_ARC_ADJUSTMENTS = 48,
	CA_USE_ENEMY_ACCURACY_SCALING = 49,
	CA_CAN_CHARGE = 50,
	CA_REMOVE_AREA_SET_WILL_ADVANCE_WHEN_DEFENSIVE_AREA_REACHED = 51,
	CA_USE_VEHICLE_ATTACK = 52,
	CA_USE_VEHICLE_ATTACK_IF_VEHICLE_HAS_MOUNTED_GUNS = 53,
	CA_ALWAYS_EQUIP_BEST_WEAPON = 54,
	CA_CAN_SEE_UNDERWATER_PEDS = 55,
	CA_DISABLE_AIM_AT_AI_TARGETS_IN_HELIS = 56,
	CA_DISABLE_SEEK_DUE_TO_LINE_OF_SIGHT = 57,
	CA_DISABLE_FLEE_FROM_COMBAT = 58,
	CA_DISABLE_TARGET_CHANGES_DURING_VEHICLE_PURSUIT = 59,
	CA_CAN_THROW_SMOKE_GRENADE = 60,
	CA_CLEAR_AREA_SET_DEFENSIVE_IF_DEFENSIVE_CANNOT_BE_REACHED = 62,
	CA_DISABLE_BLOCK_FROM_PURSUE_DURING_VEHICLE_CHASE = 64,
	CA_DISABLE_SPIN_OUT_DURING_VEHICLE_CHASE = 65,
	CA_DISABLE_CRUISE_IN_FRONT_DURING_BLOCK_DURING_VEHICLE_CHASE = 66,
	CA_CAN_IGNORE_BLOCKED_LOS_WEIGHTING = 67,
	CA_DISABLE_REACT_TO_BUDDY_SHOT = 68,
	CA_PREFER_NAVMESH_DURING_VEHICLE_CHASE = 69,
	CA_ALLOWED_TO_AVOID_OFFROAD_DURING_VEHICLE_CHASE = 70,
	CA_PERMIT_CHARGE_BEYOND_DEFENSIVE_AREA = 71,
	CA_USE_ROCKETS_AGAINST_VEHICLES_ONLY = 72,
	CA_DISABLE_TACTICAL_POINTS_WITHOUT_CLEAR_LOS = 73,
	CA_DISABLE_PULL_ALONGSIDE_DURING_VEHICLE_CHASE = 74,
	CA_DISABLE_ALL_RANDOMS_FLEE = 78,
	CA_WILL_GENERATE_DEAD_PED_SEEN_SCRIPT_EVENTS = 79,
	CA_USE_MAX_SENSE_RANGE_WHEN_RECEIVING_EVENTS = 80,
	CA_RESTRICT_IN_VEHICLE_AIMING_TO_CURRENT_SIDE = 81,
	CA_USE_DEFAULT_BLOCKED_LOS_POSITION_AND_DIRECTION = 82,
	CA_REQUIRES_LOS_TO_AIM = 83,
	CA_CAN_CRUISE_AND_BLOCK_IN_VEHICLE = 84,
	CA_PREFER_AIR_COMBAT_WHEN_IN_AIRCRAFT = 85,
	CA_ALLOW_DOG_FIGHTING = 86,
	CA_PREFER_NON_AIRCRAFT_TARGETS = 87,
	CA_PREFER_KNOWN_TARGETS_WHEN_COMBAT_CLOSEST_TARGET = 88,
	CA_FORCE_CHECK_ATTACK_ANGLE_FOR_MOUNTED_GUNS = 89,
	CA_BLOCK_FIRE_FOR_VEHICLE_PASSENGER_MOUNTED_GUNS = 90
};

enum PedBoneTag {
	BONETAG_NULL = -1,

	BONETAG_ROOT = 0,
	BONETAG_PELVIS = 11816,
	BONETAG_SPINE = 23553,
	BONETAG_SPINE1 = 24816,
	BONETAG_SPINE2 = 24817,
	BONETAG_SPINE3 = 24818,
	BONETAG_NECK = 39317,
	BONETAG_HEAD = 31086,
	BONETAG_R_CLAVICLE = 10706,
	BONETAG_R_UPPERARM = 40269,
	BONETAG_R_FOREARM = 28252,
	BONETAG_R_HAND = 57005,
	BONETAG_R_FINGER0 = 58866,
	BONETAG_R_FINGER01 = 64016,
	BONETAG_R_FINGER02 = 64017,
	BONETAG_R_FINGER1 = 58867,
	BONETAG_R_FINGER11 = 64096,
	BONETAG_R_FINGER12 = 64097,
	BONETAG_R_FINGER2 = 58868,
	BONETAG_R_FINGER21 = 64112,
	BONETAG_R_FINGER22 = 64113,
	BONETAG_R_FINGER3 = 58869,
	BONETAG_R_FINGER31 = 64064,
	BONETAG_R_FINGER32 = 64065,
	BONETAG_R_FINGER4 = 58870,
	BONETAG_R_FINGER41 = 64080,
	BONETAG_R_FINGER42 = 64081,

	BONETAG_L_CLAVICLE = 64729,
	BONETAG_L_UPPERARM = 45509,
	BONETAG_L_FOREARM = 61163,
	BONETAG_L_HAND = 18905,
	BONETAG_L_FINGER0 = 26610,
	BONETAG_L_FINGER01 = 4089,
	BONETAG_L_FINGER02 = 4090,
	BONETAG_L_FINGER1 = 26611,
	BONETAG_L_FINGER11 = 4169,
	BONETAG_L_FINGER12 = 4170,
	BONETAG_L_FINGER2 = 26612,
	BONETAG_L_FINGER21 = 4185,
	BONETAG_L_FINGER22 = 4186,
	BONETAG_L_FINGER3 = 26613,
	BONETAG_L_FINGER31 = 4137,
	BONETAG_L_FINGER32 = 4138,
	BONETAG_L_FINGER4 = 26614,
	BONETAG_L_FINGER41 = 4153,
	BONETAG_L_FINGER42 = 4154,

	BONETAG_L_THIGH = 58271,
	BONETAG_L_CALF = 63931,
	BONETAG_L_FOOT = 14201,
	BONETAG_L_TOE = 2108,
	BONETAG_R_THIGH = 51826,
	BONETAG_R_CALF = 36864,
	BONETAG_R_FOOT = 52301,
	BONETAG_R_TOE = 20781,

	BONETAG_PH_L_HAND = 60309,
	BONETAG_PH_R_HAND = 28422
};

enum PedFlag {
	//Ped Config Flags
	PCF_PhoneDisableTextingAnimations = 242,
	PCF_PhoneDisableTalkingAnimations = 243,
	PCF_PhoneDisableCameraAnimations = 244,
	PCF_DisableShockingEvents = 294,
	PCF_DisableTalkTo = 329,

	//Ped Reset Flags
	PRF_DisablePlayerJumping = 46,
	PRF_DisablePlayerVaulting = 47,
	PRF_DisableSecondaryAnimationTasks = 58
};

enum AnimationFlag
{
	AF_DEFAULT = 0,
	AF_LOOPING = 1,
	AF_HOLD_LAST_FRAME = 2,
	AF_REPOSITION_WHEN_FINISHED = 4,
	AF_NOT_INTERRUPTABLE = 8,
	AF_UPPERBODY = 16,
	AF_SECONDARY = 32,
	AF_REORIENT_WHEN_FINISHED = 64,
	AF_ABORT_ON_PED_MOVEMENT = 128,
	AF_ADDITIVE = 256,
	AF_TURN_OFF_COLLISION = 512,
	AF_OVERRIDE_PHYSICS = 1024,
	AF_IGNORE_GRAVITY = 2048,
	AF_EXTRACT_INITIAL_OFFSET = 4096,
	AF_EXIT_AFTER_INTERRUPTED = 8192,
	AF_TAG_SYNC_IN = 16384,
	AF_TAG_SYNC_OUT = 32768,
	AF_TAG_SYNC_CONTINUOUS = 65536,
	AF_FORCE_START = 131072,
	AF_USE_KINEMATIC_PHYSICS = 262144,
	AF_USE_MOVER_EXTRACTION = 524288,
	AF_HIDE_WEAPON = 1048576,
	AF_ENDS_IN_DEAD_POSE = 2097152,
	AF_ACTIVATE_RAGDOLL_ON_COLLISION = 4194304,
	AF_DONT_EXIT_ON_DEATH = 8388608,
	AF_ABORT_ON_WEAPON_DAMAGE = 16777216,
	AF_DISABLE_FORCED_PHYSICS_UPDATE = 33554432,
	AF_PROCESS_ATTACHMENTS_ON_START = 67108864,
	AF_EXPAND_PED_CAPSULE_FROM_SKELETON = 134217728,
	AF_USE_ALTERNATIVE_FP_ANIM = 268435456,
	AF_BLENDOUT_WRT_LAST_FRAME = 536870912,
	AF_USE_FULL_BLENDING = 1073741824
};

constexpr int defaultAF = AF_NOT_INTERRUPTABLE | AF_TAG_SYNC_IN | AF_TAG_SYNC_OUT | AF_HIDE_WEAPON | AF_ABORT_ON_WEAPON_DAMAGE | AF_EXIT_AFTER_INTERRUPTED;
constexpr int upperAF = AF_NOT_INTERRUPTABLE | AF_UPPERBODY | AF_TAG_SYNC_IN | AF_TAG_SYNC_OUT | AF_HIDE_WEAPON | AF_ABORT_ON_WEAPON_DAMAGE | AF_EXIT_AFTER_INTERRUPTED;
constexpr int upperSecondaryAF = AF_NOT_INTERRUPTABLE | AF_UPPERBODY | AF_TAG_SYNC_CONTINUOUS | AF_SECONDARY | AF_HIDE_WEAPON | AF_ABORT_ON_WEAPON_DAMAGE | AF_EXIT_AFTER_INTERRUPTED;

enum ScriptLookFlag
{
	SLF_DEFAULT = 0,
	SLF_SLOW_TURN_RATE = 1,
	SLF_FAST_TURN_RATE = 2,
	SLF_EXTEND_YAW_LIMIT = 4,
	SLF_EXTEND_PITCH_LIMIT = 8,
	SLF_WIDEST_YAW_LIMIT = 16,
	SLF_WIDEST_PITCH_LIMIT = 32,
	SLF_NARROW_YAW_LIMIT = 64,
	SLF_NARROW_PITCH_LIMIT = 128,
	SLF_NARROWEST_YAW_LIMIT = 256,
	SLF_NARROWEST_PITCH_LIMIT = 512,
	SLF_USE_TORSO = 1024,
	SLF_WHILE_NOT_IN_FOV = 2048,
	SLF_USE_CAMERA_FOCUS = 4096,
	SLF_USE_EYES_ONLY = 8192,
	SLF_USE_LOOK_DIR = 16384,
	SLF_FROM_SCRIPT = 32768,
	SLF_USE_REF_DIR_ABSOLUTE = 65536
};

enum AlternateAnimType
{
	AAT_IDLE,
	AAT_WALK,
	AAT_RUN,
	AAT_SPRINT
};

enum ControlType {
	PLAYER_CONTROL = 0,
	CAMERA_CONTROL,
	FRONTEND_CONTROL
};

enum ControlAction {
	INPUT_NEXT_CAMERA = 0,
	INPUT_LOOK_LR,
	INPUT_LOOK_UD,
	INPUT_LOOK_UP_ONLY,
	INPUT_LOOK_DOWN_ONLY,
	INPUT_LOOK_LEFT_ONLY,
	INPUT_LOOK_RIGHT_ONLY,
	INPUT_CINEMATIC_SLOWMO,
	INPUT_SCRIPTED_FLY_UD,
	INPUT_SCRIPTED_FLY_LR,
	INPUT_SCRIPTED_FLY_ZUP,
	INPUT_SCRIPTED_FLY_ZDOWN,
	INPUT_WEAPON_WHEEL_UD,
	INPUT_WEAPON_WHEEL_LR,
	INPUT_WEAPON_WHEEL_NEXT,
	INPUT_WEAPON_WHEEL_PREV,
	INPUT_SELECT_NEXT_WEAPON,
	INPUT_SELECT_PREV_WEAPON,
	INPUT_SKIP_CUTSCENE,
	INPUT_CHARACTER_WHEEL,
	INPUT_MULTIPLAYER_INFO,
	INPUT_SPRINT,
	INPUT_JUMP,
	INPUT_ENTER,
	INPUT_ATTACK,
	INPUT_AIM,
	INPUT_LOOK_BEHIND,
	INPUT_PHONE,
	INPUT_SPECIAL_ABILITY,
	INPUT_SPECIAL_ABILITY_SECONDARY,
	INPUT_MOVE_LR,
	INPUT_MOVE_UD,
	INPUT_MOVE_UP_ONLY,
	INPUT_MOVE_DOWN_ONLY,
	INPUT_MOVE_LEFT_ONLY,
	INPUT_MOVE_RIGHT_ONLY,
	INPUT_DUCK,
	INPUT_SELECT_WEAPON,
	INPUT_PICKUP,
	INPUT_SNIPER_ZOOM,
	INPUT_SNIPER_ZOOM_IN_ONLY,
	INPUT_SNIPER_ZOOM_OUT_ONLY,
	INPUT_SNIPER_ZOOM_IN_SECONDARY,
	INPUT_SNIPER_ZOOM_OUT_SECONDARY,
	INPUT_COVER,
	INPUT_RELOAD,
	INPUT_TALK,
	INPUT_DETONATE,
	INPUT_HUD_SPECIAL,
	INPUT_ARREST,
	INPUT_ACCURATE_AIM,
	INPUT_CONTEXT,
	INPUT_CONTEXT_SECONDARY,
	INPUT_WEAPON_SPECIAL,
	INPUT_WEAPON_SPECIAL_TWO,
	INPUT_DIVE,
	INPUT_DROP_WEAPON,
	INPUT_DROP_AMMO,
	INPUT_THROW_GRENADE,
	INPUT_VEH_MOVE_LR,
	INPUT_VEH_MOVE_UD,
	INPUT_VEH_MOVE_UP_ONLY,
	INPUT_VEH_MOVE_DOWN_ONLY,
	INPUT_VEH_MOVE_LEFT_ONLY,
	INPUT_VEH_MOVE_RIGHT_ONLY,
	INPUT_VEH_SPECIAL,
	INPUT_VEH_GUN_LR,
	INPUT_VEH_GUN_UD,
	INPUT_VEH_AIM,
	INPUT_VEH_ATTACK,
	INPUT_VEH_ATTACK2,
	INPUT_VEH_ACCELERATE,
	INPUT_VEH_BRAKE,
	INPUT_VEH_DUCK,
	INPUT_VEH_HEADLIGHT,
	INPUT_VEH_EXIT,
	INPUT_VEH_HANDBRAKE,
	INPUT_VEH_HOTWIRE_LEFT,
	INPUT_VEH_HOTWIRE_RIGHT,
	INPUT_VEH_LOOK_BEHIND,
	INPUT_VEH_CIN_CAM,
	INPUT_VEH_NEXT_RADIO,
	INPUT_VEH_PREV_RADIO,
	INPUT_VEH_NEXT_RADIO_TRACK,
	INPUT_VEH_PREV_RADIO_TRACK,
	INPUT_VEH_RADIO_WHEEL,
	INPUT_VEH_HORN,
	INPUT_VEH_FLY_THROTTLE_UP,
	INPUT_VEH_FLY_THROTTLE_DOWN,
	INPUT_VEH_FLY_YAW_LEFT,
	INPUT_VEH_FLY_YAW_RIGHT,
	INPUT_VEH_PASSENGER_AIM,
	INPUT_VEH_PASSENGER_ATTACK,
	INPUT_VEH_SPECIAL_ABILITY_FRANKLIN,
	INPUT_VEH_STUNT_UD,
	INPUT_VEH_CINEMATIC_UD,
	INPUT_VEH_CINEMATIC_UP_ONLY,
	INPUT_VEH_CINEMATIC_DOWN_ONLY,
	INPUT_VEH_CINEMATIC_LR,
	INPUT_VEH_SELECT_NEXT_WEAPON,
	INPUT_VEH_SELECT_PREV_WEAPON,
	INPUT_VEH_ROOF,
	INPUT_VEH_JUMP,
	INPUT_VEH_GRAPPLING_HOOK,
	INPUT_VEH_SHUFFLE,
	INPUT_VEH_DROP_PROJECTILE,
	INPUT_VEH_MOUSE_CONTROL_OVERRIDE,
	INPUT_VEH_FLY_ROLL_LR,
	INPUT_VEH_FLY_ROLL_LEFT_ONLY,
	INPUT_VEH_FLY_ROLL_RIGHT_ONLY,
	INPUT_VEH_FLY_PITCH_UD,
	INPUT_VEH_FLY_PITCH_UP_ONLY,
	INPUT_VEH_FLY_PITCH_DOWN_ONLY,
	INPUT_VEH_FLY_UNDERCARRIAGE,
	INPUT_VEH_FLY_ATTACK,
	INPUT_VEH_FLY_SELECT_NEXT_WEAPON,
	INPUT_VEH_FLY_SELECT_PREV_WEAPON,
	INPUT_VEH_FLY_SELECT_TARGET_LEFT,
	INPUT_VEH_FLY_SELECT_TARGET_RIGHT,
	INPUT_VEH_FLY_VERTICAL_FLIGHT_MODE,
	INPUT_VEH_FLY_DUCK,
	INPUT_VEH_FLY_ATTACK_CAMERA,
	INPUT_VEH_FLY_MOUSE_CONTROL_OVERRIDE,
	INPUT_VEH_SUB_TURN_LR,
	INPUT_VEH_SUB_TURN_LEFT_ONLY,
	INPUT_VEH_SUB_TURN_RIGHT_ONLY,
	INPUT_VEH_SUB_PITCH_UD,
	INPUT_VEH_SUB_PITCH_UP_ONLY,
	INPUT_VEH_SUB_PITCH_DOWN_ONLY,
	INPUT_VEH_SUB_THROTTLE_UP,
	INPUT_VEH_SUB_THROTTLE_DOWN,
	INPUT_VEH_SUB_ASCEND,
	INPUT_VEH_SUB_DESCEND,
	INPUT_VEH_SUB_TURN_HARD_LEFT,
	INPUT_VEH_SUB_TURN_HARD_RIGHT,
	INPUT_VEH_SUB_MOUSE_CONTROL_OVERRIDE,
	INPUT_VEH_PUSHBIKE_PEDAL,
	INPUT_VEH_PUSHBIKE_SPRINT,
	INPUT_VEH_PUSHBIKE_FRONT_BRAKE,
	INPUT_VEH_PUSHBIKE_REAR_BRAKE,
	INPUT_MELEE_ATTACK_LIGHT,
	INPUT_MELEE_ATTACK_HEAVY,
	INPUT_MELEE_ATTACK_ALTERNATE,
	INPUT_MELEE_BLOCK,
	INPUT_PARACHUTE_DEPLOY,
	INPUT_PARACHUTE_DETACH,
	INPUT_PARACHUTE_TURN_LR,
	INPUT_PARACHUTE_TURN_LEFT_ONLY,
	INPUT_PARACHUTE_TURN_RIGHT_ONLY,
	INPUT_PARACHUTE_PITCH_UD,
	INPUT_PARACHUTE_PITCH_UP_ONLY,
	INPUT_PARACHUTE_PITCH_DOWN_ONLY,
	INPUT_PARACHUTE_BRAKE_LEFT,
	INPUT_PARACHUTE_BRAKE_RIGHT,
	INPUT_PARACHUTE_SMOKE,
	INPUT_PARACHUTE_PRECISION_LANDING,
	INPUT_MAP,
	INPUT_SELECT_WEAPON_UNARMED,
	INPUT_SELECT_WEAPON_MELEE,
	INPUT_SELECT_WEAPON_HANDGUN,
	INPUT_SELECT_WEAPON_SHOTGUN,
	INPUT_SELECT_WEAPON_SMG,
	INPUT_SELECT_WEAPON_AUTO_RIFLE,
	INPUT_SELECT_WEAPON_SNIPER,
	INPUT_SELECT_WEAPON_HEAVY,
	INPUT_SELECT_WEAPON_SPECIAL,
	INPUT_SELECT_CHARACTER_MICHAEL,
	INPUT_SELECT_CHARACTER_FRANKLIN,
	INPUT_SELECT_CHARACTER_TREVOR,
	INPUT_SELECT_CHARACTER_MULTIPLAYER,
	INPUT_SAVE_REPLAY_CLIP,
	INPUT_SPECIAL_ABILITY_PC,
	INPUT_CELLPHONE_UP,
	INPUT_CELLPHONE_DOWN,
	INPUT_CELLPHONE_LEFT,
	INPUT_CELLPHONE_RIGHT,
	INPUT_CELLPHONE_SELECT,
	INPUT_CELLPHONE_CANCEL,
	INPUT_CELLPHONE_OPTION,
	INPUT_CELLPHONE_EXTRA_OPTION,
	INPUT_CELLPHONE_SCROLL_FORWARD,
	INPUT_CELLPHONE_SCROLL_BACKWARD,
	INPUT_CELLPHONE_CAMERA_FOCUS_LOCK,
	INPUT_CELLPHONE_CAMERA_GRID,
	INPUT_CELLPHONE_CAMERA_SELFIE,
	INPUT_CELLPHONE_CAMERA_DOF,
	INPUT_CELLPHONE_CAMERA_EXPRESSION,
	INPUT_FRONTEND_DOWN,
	INPUT_FRONTEND_UP,
	INPUT_FRONTEND_LEFT,
	INPUT_FRONTEND_RIGHT,
	INPUT_FRONTEND_RDOWN,
	INPUT_FRONTEND_RUP,
	INPUT_FRONTEND_RLEFT,
	INPUT_FRONTEND_RRIGHT,
	INPUT_FRONTEND_AXIS_X,
	INPUT_FRONTEND_AXIS_Y,
	INPUT_FRONTEND_RIGHT_AXIS_X,
	INPUT_FRONTEND_RIGHT_AXIS_Y,
	INPUT_FRONTEND_PAUSE,
	INPUT_FRONTEND_PAUSE_ALTERNATE,
	INPUT_FRONTEND_ACCEPT,
	INPUT_FRONTEND_CANCEL,
	INPUT_FRONTEND_X,
	INPUT_FRONTEND_Y,
	INPUT_FRONTEND_LB,
	INPUT_FRONTEND_RB,
	INPUT_FRONTEND_LT,
	INPUT_FRONTEND_RT,
	INPUT_FRONTEND_LS,
	INPUT_FRONTEND_RS,
	INPUT_FRONTEND_LEADERBOARD,
	INPUT_FRONTEND_SOCIAL_CLUB,
	INPUT_FRONTEND_SOCIAL_CLUB_SECONDARY,
	INPUT_FRONTEND_DELETE,
	INPUT_FRONTEND_ENDSCREEN_ACCEPT,
	INPUT_FRONTEND_ENDSCREEN_EXPAND,
	INPUT_FRONTEND_SELECT,
	INPUT_SCRIPT_LEFT_AXIS_X,
	INPUT_SCRIPT_LEFT_AXIS_Y,
	INPUT_SCRIPT_RIGHT_AXIS_X,
	INPUT_SCRIPT_RIGHT_AXIS_Y,
	INPUT_SCRIPT_RUP,
	INPUT_SCRIPT_RDOWN,
	INPUT_SCRIPT_RLEFT,
	INPUT_SCRIPT_RRIGHT,
	INPUT_SCRIPT_LB,
	INPUT_SCRIPT_RB,
	INPUT_SCRIPT_LT,
	INPUT_SCRIPT_RT,
	INPUT_SCRIPT_LS,
	INPUT_SCRIPT_RS,
	INPUT_SCRIPT_PAD_UP,
	INPUT_SCRIPT_PAD_DOWN,
	INPUT_SCRIPT_PAD_LEFT,
	INPUT_SCRIPT_PAD_RIGHT,
	INPUT_SCRIPT_SELECT,
	INPUT_CURSOR_ACCEPT,
	INPUT_CURSOR_CANCEL,
	INPUT_CURSOR_X,
	INPUT_CURSOR_Y,
	INPUT_CURSOR_SCROLL_UP,
	INPUT_CURSOR_SCROLL_DOWN,
	INPUT_ENTER_CHEAT_CODE,
	INPUT_INTERACTION_MENU,
	INPUT_MP_TEXT_CHAT_ALL,
	INPUT_MP_TEXT_CHAT_TEAM,
	INPUT_MP_TEXT_CHAT_FRIENDS,
	INPUT_MP_TEXT_CHAT_CREW,
	INPUT_PC_PUSH_TO_TALK,
	INPUT_CREATOR_LS,
	INPUT_CREATOR_RS,
	INPUT_CREATOR_LT,
	INPUT_CREATOR_RT,
	INPUT_CREATOR_MENU_TOGGLE,
	INPUT_CREATOR_ACCEPT,
	INPUT_CREATOR_DELETE,
	INPUT_ATTACK2,
	INPUT_RAPPEL_JUMP,
	INPUT_RAPPEL_LONG_JUMP,
	INPUT_RAPPEL_SMASH_WINDOW,
	INPUT_PREV_WEAPON,
	INPUT_NEXT_WEAPON,
	INPUT_MELEE_ATTACK1,
	INPUT_MELEE_ATTACK2,
	INPUT_WHISTLE,
	INPUT_MOVE_LEFT,
	INPUT_MOVE_RIGHT,
	INPUT_MOVE_UP,
	INPUT_MOVE_DOWN,
	INPUT_LOOK_LEFT,
	INPUT_LOOK_RIGHT,
	INPUT_LOOK_UP,
	INPUT_LOOK_DOWN,
	INPUT_SNIPER_ZOOM_IN,
	INPUT_SNIPER_ZOOM_OUT,
	INPUT_SNIPER_ZOOM_IN_ALTERNATE,
	INPUT_SNIPER_ZOOM_OUT_ALTERNATE,
	INPUT_VEH_MOVE_LEFT,
	INPUT_VEH_MOVE_RIGHT,
	INPUT_VEH_MOVE_UP,
	INPUT_VEH_MOVE_DOWN,
	INPUT_VEH_GUN_LEFT,
	INPUT_VEH_GUN_RIGHT,
	INPUT_VEH_GUN_UP,
	INPUT_VEH_GUN_DOWN,
	INPUT_VEH_LOOK_LEFT,
	INPUT_VEH_LOOK_RIGHT,
	INPUT_REPLAY_START_STOP_RECORDING,
	INPUT_REPLAY_START_STOP_RECORDING_SECONDARY,
	INPUT_SCALED_LOOK_LR,
	INPUT_SCALED_LOOK_UD,
	INPUT_SCALED_LOOK_UP_ONLY,
	INPUT_SCALED_LOOK_DOWN_ONLY,
	INPUT_SCALED_LOOK_LEFT_ONLY,
	INPUT_SCALED_LOOK_RIGHT_ONLY,
	INPUT_REPLAY_MARKER_DELETE,
	INPUT_REPLAY_CLIP_DELETE,
	INPUT_REPLAY_PAUSE,
	INPUT_REPLAY_REWIND,
	INPUT_REPLAY_FFWD,
	INPUT_REPLAY_NEWMARKER,
	INPUT_REPLAY_RECORD,
	INPUT_REPLAY_SCREENSHOT,
	INPUT_REPLAY_HIDEHUD,
	INPUT_REPLAY_STARTPOINT,
	INPUT_REPLAY_ENDPOINT,
	INPUT_REPLAY_ADVANCE,
	INPUT_REPLAY_BACK,
	INPUT_REPLAY_TOOLS,
	INPUT_REPLAY_RESTART,
	INPUT_REPLAY_SHOWHOTKEY,
	INPUT_REPLAY_CYCLEMARKERLEFT,
	INPUT_REPLAY_CYCLEMARKERRIGHT,
	INPUT_REPLAY_FOVINCREASE,
	INPUT_REPLAY_FOVDECREASE,
	INPUT_REPLAY_CAMERAUP,
	INPUT_REPLAY_CAMERADOWN,
	INPUT_REPLAY_SAVE,
	INPUT_REPLAY_TOGGLETIME,
	INPUT_REPLAY_TOGGLETIPS,
	INPUT_REPLAY_PREVIEW,
	INPUT_REPLAY_TOGGLE_TIMELINE,
	INPUT_REPLAY_TIMELINE_PICKUP_CLIP,
	INPUT_REPLAY_TIMELINE_DUPLICATE_CLIP,
	INPUT_REPLAY_TIMELINE_PLACE_CLIP,
	INPUT_REPLAY_CTRL,
	INPUT_REPLAY_TIMELINE_SAVE,
	INPUT_REPLAY_PREVIEW_AUDIO,
	INPUT_VEH_DRIVE_LOOK,
	INPUT_VEH_DRIVE_LOOK2,
	INPUT_VEH_FLY_ATTACK2,
	INPUT_RADIO_WHEEL_UD,
	INPUT_RADIO_WHEEL_LR,
	INPUT_VEH_SLOWMO_UP,
	INPUT_VEH_SLOWMO_UP_ONLY,
	INPUT_VEH_SLOWMO_DOWN_ONLY,
	INPUT_VEH_HYDRAULICS_CONTROL_TOGGLE,
	INPUT_VEH_HYDRAULICS_CONTROL_LEFT,
	INPUT_VEH_HYDRAULICS_CONTROL_RIGHT,
	INPUT_VEH_HYDRAULICS_CONTROL_UP,
	INPUT_VEH_HYDRAULICS_CONTROL_DOWN,
	INPUT_VEH_HYDRAULICS_CONTROL_LR,
	INPUT_VEH_HYDRAULICS_CONTROL_UD,
	INPUT_SWITCH_VISOR,
	INPUT_VEH_MELEE_HOLD,
	INPUT_VEH_MELEE_LEFT,
	INPUT_VEH_MELEE_RIGHT,
	INPUT_MAP_POI,
	INPUT_REPLAY_SNAPMATIC_PHOTO,
	INPUT_VEH_CAR_JUMP,
	INPUT_VEH_ROCKET_BOOST,
	INPUT_VEH_FLY_BOOST,
	INPUT_VEH_PARACHUTE,
	INPUT_VEH_BIKE_WINGS,
	INPUT_VEH_FLY_BOMB_BAY,
	INPUT_VEH_FLY_COUNTER,
	INPUT_VEH_TRANSFORM,
	INPUT_QUAD_LOCO_REVERSE,
	INPUT_RESPAWN_FASTER,
	INPUT_HUDMARKER_SELECT,
	INPUT_EAT_SNACK,
	INPUT_USE_ARMOR,
	MAX_INPUTS
};