modded class TraderPlusMenu extends UIScriptedMenu
{

    float moneyTimerUpdate = 0;

    override void MoneyUpdate()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        TraderPlusHelper.GetPlayerMoney(player, TraderID);
        m_playerMoney = TraderPlusHelper.cacheMoney;
        string stringMoney = TraderPlusHelper.IntToCurrencyString(m_playerMoney, ",");
        m_PlayerMoneyText.SetText("#tpm_money"+ " " +stringMoney);
    }

    override void Update(float timeslice)
    {
        super.Update(timeslice);
        moneyTimerUpdate += timeslice;
        if(moneyTimerUpdate > 1){
            moneyTimerUpdate = 0;
            GetRPCManager().SendRPC("TraderPlus", "GetMoneyRequest",  null, true, NULL);
            MoneyUpdate();
        }
    }

}