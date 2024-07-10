class CfgPatches
{
    class RR_Persistence
    {
        author = "Jenna + Azura";
		requiredAddons[]=
		{
			"A3_Modules_F",
			"RR_core",
			"ls_ammobox"
		};
		requiredVersion=0.1;
		units[]=
		{
			"RR_Persistence_Saveloadouts_F",
			"RR_commonBox_F"
		};
		weapons[]={};
    };
};

class CfgFunctions
{
	class RR_Persistence
	{
		class Functions 
		{
			file = "\RR_Persistence\functions";
			class loadUnit{};
			class postinitServer{};
			class saveLoadout{};
			class SaveAllLoadouts{};
			class initCommonBox{};
			class insertVehicleChildren{};
			class initArsenal{};
		};
	};
};

class extended_postinit_eventhandlers
{
	class RR_Persistence
	{
		init="call compile preprocessFileLineNumbers 'RR_Persistence\xeh_postinit.sqf'";
	};
	class RR_commonBox_F
	{
		init = "_this call RR_fnc_initCommonBox";
	};
};


class CfgVehicles
{
	class Logic;
	class Module_F : Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit;					// Default edit box (i.e. text input field)
			class Combo;				// Default combo box (i.e. drop-down menu)
			class Checkbox;				// Default checkbox (returned value is Boolean)
			class CheckboxNumber;		// Default checkbox (returned value is Number)
			class ModuleDescription;	// Module description
			class Units;				// Selection of units on which the module is applied
		};

		// Description base classes (for more information see below):
		class ModuleDescription
		{
			class AnyBrain;
		};
	};

	class RR_Persistence_Saveloadouts_F : Module_F
	{
		// Standard object definitions:
		scope = 1;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Save All Loadouts";				// Name displayed in the menu
		category = "Persistence";
		scopecurator = 2;
		function = "RR_Persistence_fnc_SaveAllLoadouts";	// Name of function triggered once conditions are met
		functionPriority = 1;				// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
		isGlobal = 0;						// 0 for server only execution, 1 for global execution, 2 for persistent global execution
		is3DEN = 0;							// 1 to run init function in Eden Editor as well

	};
	class ls_carrybox_base;
	class RR_commonBox_F : ls_carrybox_base
	{
		displayName = "Repo's Raiders Common Box";
        	armor = 10e10;
		editorCategory = "EdCat_Supplies";
		scopecurator = 2;
		knd_crates_hasBeacon = 1;
		side = 3;
		ace_dragging_ignoreWeight=1;
        	ace_dragging_ignoreWeightCarry=1;
		maximumLoad = 10e10;
	};

};
