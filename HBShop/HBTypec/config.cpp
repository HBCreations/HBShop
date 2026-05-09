class CfgPatches
{
	class HBTypec
	{
		requiredAddons[]=
		{
			"JM_CF_Scripts"
		};
		units[]={};
		weapons[]={};
	};
};
class CfgMods
{
	class HBTypec
	{
		type="mod";
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"HBShop/HBTypec/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"HBShop/HBTypec/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"HBShop/HBTypec/scripts/5_Mission"
				};
			};
		};
	};
};
