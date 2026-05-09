class CfgPatches
{
    class HBShop
    {
            requiredAddons[]=
            {
                "DZ_Data",
                "DZ_Scripts"
            };
    };
};

class CfgMods
{
    class HBShop
    {
        type = "mod";
                inputs = "HBShop/scripts/3_Game/ButtonInputs.xml";

        class defs
        {
            class gameScriptModule
			{
                files[] = {"HBShop/scripts/3_game"};
			};
            class worldScriptModule
			{
                files[] = {"HBShop/scripts/4_world"};
			};
            class missionScriptModule
            {
                files[] = {"HBShop/scripts/5_mission"};
            };
        };
    };
};