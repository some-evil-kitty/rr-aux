// arsenal init 
 
params ["_object"]; 
 
if !(local _object) exitwith {}; 
 

private _facewear = [ConfigFile >> "CfgGlasses"] call BIS_fnc_getCfgSubClasses; 
private _allUniforms = ("getNumber (_x /'scope') == 2 && getNumber (_x /'itemInfo' /'type') == 801" configClasses (configFile /"cfgWeapons") apply {configName _x});  
private _allHelmets = ("getNumber (_x /'scope') == 2 && getNumber (_x /'itemInfo' /'type') == 605" configClasses (configFile /"cfgWeapons") apply {configName _x});
private _allNVG = ("getNumber (_x /'scope') == 2 && getNumber (_x /'itemInfo' /'type') == 616" configClasses (configFile /"cfgWeapons") apply {configName _x});  
private _filteredweapons = _facewear + _allUniforms + _allHelmets + _allNVG; 

 
 
private _whitelist = [ 
"ItemMap", 
"ItemGPS","I_UAVTerminal", 
"C_UavTerminal", 
"O_UavTerminal", 
"I_E_UavTerminal", 
"B_UavTerminal", 
"ItemCompass", 
"MineDetector", 
"ToolKit", 
"ItemWatch",  
"JLTS_Clone_comlink", 
"JLTS_CloneBinocular_black",
"JLTS_CloneBinocular",
"knd_blackbinocs",
"knd_testbinocs",
"ls_gar_glidepackClosed_backpack",
"B_Parachute",
"knd_spacek_folded",
"knd_spacek_mag",
"knd_e11_mag",
"acc_flashlight",
"knd_e11_scope_attachment",
"knd_dh17_mag",
"knd_dh17",
"knd_A180_pistol_mag",
"knd_pistol_a180_F",
"knd_DC17_pistol_mag",
"knd_pistol_dc17_F",
"knd_dc17_muzzle_attachment",
"B_FieldPack_blk",
"knd_woundglue",
"knd_bacta",
"ACE_surgicalKit",
"knd_symoxin",
"ACE_salineIV_500",
"ACE_tourniquet",
"ACE_splint",
"knd_comaren",
"B_Messenger_Black_F",
"ls_mandalorian_demo_backpack"
]; 

 
//Fine tuning 
_filteredweapons = _filteredweapons + _whitelist;
 
 
[_object, _filteredweapons,true] call ace_arsenal_fnc_initBox 
