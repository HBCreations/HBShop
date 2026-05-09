modded class TraderPlusCore {
    override void InitRPC()
    {
        if (GetGame().IsServer())
        {

            GetRPCManager().AddRPC("TraderPlus", "GetTradeRequest", m_TraderPlusServer, SingeplayerExecutionType.Client);
            GetRPCManager().AddRPC("TraderPlus", "GetStockRequestBasedOnID", m_TraderPlusServer, SingeplayerExecutionType.Client);
            GetRPCManager().AddRPC("TraderPlus", "GetCarNameReceiptRequest", this, SingeplayerExecutionType.Client);
            GetRPCManager().AddRPC("TraderPlus", "GetInsuranceRequest", m_TraderPlusServer, SingeplayerExecutionType.Client);
            GetRPCManager().AddRPC( "TraderPlus", "GetMoneyRequest", this, SingeplayerExecutionType.Client );
        }
        else
        {

            GetRPCManager().AddRPC("TraderPlus", "GetInsuranceResponse", m_TraderPlusClient, SingeplayerExecutionType.Server);
            GetRPCManager().AddRPC("TraderPlus", "GetStockResponseBasedOnID", m_TraderPlusClient, SingeplayerExecutionType.Server);
            GetRPCManager().AddRPC("TraderPlus", "GetTraderPlusGnrlConfigClient", this, SingeplayerExecutionType.Server);
            GetRPCManager().AddRPC("TraderPlus", "GetPriceRequestFromCategory", m_TraderPlusClient, SingeplayerExecutionType.Server);
            GetRPCManager().AddRPC("TraderPlus", "GetCarNameReceiptResponse", this, SingeplayerExecutionType.Server);
            GetRPCManager().AddRPC( "TraderPlus", "GetMoneyResponse", this, SingeplayerExecutionType.Server );
        }
    }

    void GetMoneyRequest(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if( type == CallType.Server )
		{
            KR_JsonDatabaseHandler targetdata = KR_JsonDatabaseHandler.LoadPlayerData(sender.GetPlainId(),  sender.GetName());
            TraderPlusHelper.cacheMoney = targetdata.GetBankCredit();
            GetRPCManager().SendRPC("TraderPlus", "GetMoneyResponse",  new Param1< float >(targetdata.GetBankCredit()), true, sender);
        }       
    }

    void GetMoneyResponse(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if( type == CallType.Client )
		{
            Param1<float> params;
            if ( !ctx.Read( params ) ) return;
            TraderPlusHelper.cacheMoney = params.param1;
        }       
    }
}