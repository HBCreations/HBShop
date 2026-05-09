class CfgPatches
{
	class HBTypea
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class HBTypea
	{
		dir="HBTypea";
		type="mod";
		dependencies[]=
		{
			"Mission",
			"World",
			"Game"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"HBShop/HBTypea/Register"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"HBShop/HBTypea/Register"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"HBShop/HBTypea/Register"
				};
			};
		};
	};
};
