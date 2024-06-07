// Saves a unit's loadout, server only command
//
//
//


if (isServer) exitwith {};

params ["_unit"];

private _id = getPlayerUID _unit;

private _loadouthashmap = profileNameSpace getVariable ["RR_Persistence_LoadoutsHashmap",createHashmap];

private _loadout = [_unit] call CBA_fnc_getLoadout;

_loadouthashmap set [_id,_loadout];