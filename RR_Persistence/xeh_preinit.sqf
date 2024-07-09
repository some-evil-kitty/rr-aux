[
    "RR_enablePersistence", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    "Enable Persistence", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["Repo's Revolutionaries","Persistence"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    false, // data for this setting: [min, max, default, number of shown trailing decimals]
    true, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;
