class CfgPatches
{
    class RR_Persistence
    {
        author = "Jenna + Azura";
		requiredAddons[]=
		{

		};
		requiredVersion=0.1;
		units[]=
		{
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
		};
	};
};
