class CfgPatches
{
    class RR_Persistence
    {
        author = "Jenna + Azura";
		requiredAddons[]=
		{
			"A3_Modules_F",
			"RR_core"
		};
		requiredVersion=0.1;
		units[]=
		{
			"RR_Persistence_SaveLoadouts"
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
		};
	};
};

class extended_postinit_eventhandlers
{
	class RR_Persistence
	{
		init="call compile preprocessFileLineNumbers 'RR_Persistence\xeh_postinit.sqf'";
	}
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
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Save All Loadouts";				// Name displayed in the menu
		category = "Effects";
		scopecurator = 2;
		function = "RR_Persistence_fnc_SaveAllLoadouts";	// Name of function triggered once conditions are met
		functionPriority = 1;				// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
		isGlobal = 0;						// 0 for server only execution, 1 for global execution, 2 for persistent global execution
		isTriggerActivated = 1;				// 1 for module waiting until all synced triggers are activated
		isDisposable = 1;					// 1 if modules is to be disabled once it is activated (i.e. repeated trigger activation will not work)
		is3DEN = 0;							// 1 to run init function in Eden Editor as well
		curatorCanAttach = 1;				// 1 to allow Zeus to attach the module to an entity

		// 3DEN Attributes Menu Options
		canSetArea = 1;						// Allows for setting the area values in the Attributes menu in 3DEN
		canSetAreaShape = 1;				// Allows for setting "Rectangle" or "Ellipse" in Attributes menu in 3DEN
		canSetAreaHeight = 1;				// Allows for setting height or Z value in Attributes menu in 3DEN
		class AttributeValues
		{
			// This section allows you to set the default values for the attributes menu in 3DEN
			size3[] = { 100, 100, -1 };		// 3D size (x-axis radius, y-axis radius, z-axis radius)
			isRectangle = 0;				// Sets if the default shape should be a rectangle or ellipse
		};

		// Module attributes (uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific):
		class Attributes : AttributesBase
		{
			// Arguments shared by specific module type (have to be mentioned in order to be present):

			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Saves all loadouts";	// Short description, will be formatted as structured text
			sync[] = { };				// Array of synced entities (can contain base classes)
		};
	};
};