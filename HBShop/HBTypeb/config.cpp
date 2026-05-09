class CfgPatches
{
	class HBTypeb
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class HBTypeb
	{
		dir="HBTypeb";
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"HBShop/HBTypeb/scripts/4_World"
				};
			};
		};
	};
};
