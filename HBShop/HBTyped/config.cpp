class CfgPatches
{
	class HBTyped
	{
		units[]=
		{
			"MoneyRuble1",
			"MoneyRuble5",
			"MoneyRuble10",
			"MoneyRuble25",
			"MoneyRuble50",
			"MoneyRuble100"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgModels
{
	class ruble
	{
		sections[]=
		{
			"WholeObject"
		};
	};
	class keyLada
	{
		sections[]=
		{
			"WholeObject"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class MoneyRuble1: Inventory_Base
	{
		scope=2;
		displayName="1元";
		descriptionShort="人民币是一种中国的通用货币";
		model="HBShop\HBTyped\1Rmb.p3d";
		canBeSplit=1;
		rotationFlags=16;
		lootCategory="Materials";
		lootTag[]=
		{
			"Civilian",
			"Work"
		};
		itemSize[]={1,2};
		weight=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=500;
		varQuantityDestroyOnMin=1;
		destroyOnEmpty=1;
		absorbency=1;
		hiddenSelections[]=
		{
			"WholeObject"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"HBShop\HBTyped\data\ruble.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"HBShop\HBTyped\data\ruble.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"HBShop\HBTyped\data\ruble_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"HBShop\HBTyped\data\ruble_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"HBShop\HBTyped\data\ruble_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class MoneyRuble5: MoneyRuble1
	{
		model="HBShop\HBTyped\5Rmb.p3d";
		displayName="5元";
	};
	class MoneyRuble10: MoneyRuble1
	{
		model="HBShop\HBTyped\10Rmb.p3d";
		displayName="10元";
	};
/* class MoneyRuble20: MoneyRuble1
{
    model="HBShop\HBTyped\20Rmb.p3d";
    displayName="20元";
}; */
	class MoneyRuble50: MoneyRuble1
	{
		model="HBShop\HBTyped\50Rmb.p3d";
		displayName="50元";
	};
	class MoneyRuble100: MoneyRuble1
	{
		model="HBShop\HBTyped\100Rmb.p3d";
		displayName="100元";
	};
};
