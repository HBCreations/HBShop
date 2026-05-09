class TPCarryOnServer
{
    void TPCarryOnServer()
    {
    }

    void  ~TPCarryOnServer(){
    }
};

modded class TraderPlusMenu extends UIScriptedMenu
{
  void GetCarryOnStockRequest(int id, vector pos)
  {
    m_Trader = NULL;
    TraderID = id;
    TraderPos= pos;
  }
}

modded class TraderPlusMenu extends UIScriptedMenu
{
  override string GetTraderPlusLayoutPath()
  {
    return "HBShop/HBType/HBcn.layout";
  }
}

static ref TPCarryOnCore m_TPCarryOnCore;
static TPCarryOnCore GetTPCarryOnCore() {
	if ( !m_TPCarryOnCore ) {
		m_TPCarryOnCore = new TPCarryOnCore;
	}
	return m_TPCarryOnCore;
}

class TPCarryOnCore
{
  ref TPCarryOnServer m_TPCarryOnServer;

	void TPCarryOnCore()
  {
		initTPCarryCore();
  }

	void initTPCarryCore()
	{
    if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_TPCarryOnServer = new TPCarryOnServer;
		}
		InitRPC();
	}

	void ~TPCarryOnCore(){
  }

	void InitRPC()
		{
      if (GetGame().IsServer())
      {
        GetRPCManager().AddRPC("TPCarryOn", "NormalTraderRequest", m_TPCarryOnServer, SingeplayerExecutionType.Client);
        GetRPCManager().AddRPC("TPCarryOn", "VIPTraderRequest", m_TPCarryOnServer, SingeplayerExecutionType.Client);
      }
      else
			{
				GetRPCManager().AddRPC("TPCarryOn", "NormalTraderResponse", this, SingeplayerExecutionType.Server);
				GetRPCManager().AddRPC("TPCarryOn", "VIPTraderResponse", this, SingeplayerExecutionType.Server);
		  }
		}

		void NormalTraderResponse(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
		{
			if(!GetGame().IsClient())return;

			Param1<int> data;
	     if (!ctx.Read(data))
	       return;

		  OpenTraderMenu(data.param1);
		}

		void VIPTraderResponse(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
		{
			if(!GetGame().IsClient())return;

			Param1<int> data;
	     if (!ctx.Read(data))
	       return;

			OpenTraderMenu(data.param1);
		}

		void InitTraderMenu(PlayerBase player, int id)
		{
			player.m_TraderPlusMenu = new TraderPlusMenu;
			player.m_TraderPlusMenu.Init();
			GetRPCManager().SendRPC("TraderPlus", "GetInsuranceRequest",  NULL, true, NULL);
			GetRPCManager().SendRPC("TraderPlusBanking", "TraderPlusBankingRequest",  NULL, true, NULL);
			int LowUID = GarageHelpers.GetLowSteamID(GetGame().GetUserManager().GetTitleInitiator().GetUid());
			GetRPCManager().SendRPC("Garage", "GarageRequest",  new Param3<int, vector,bool>(LowUID, player.GetPosition(), false), true, NULL);
			player.m_TraderPlusMenu.GetCarryOnStockRequest(id,player.GetPosition());
		}

		void OpenTraderMenu(int id)
		{
				PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
				if ( g_Game.GetUIManager().GetMenu() == NULL )
				{
					InitTraderMenu(player,id);
					GetGame().GetUIManager().ShowScriptedMenu( player.m_TraderPlusMenu, NULL );
				}
		}
	};