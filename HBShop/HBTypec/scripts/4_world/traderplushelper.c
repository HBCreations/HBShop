modded class TraderPlusHelper
{
    static float cacheMoney = 0;
    static int GetPlayerMoney(PlayerBase player, int id)
    {
        if(!player)return 0; 
        GetRPCManager().SendRPC("TraderPlus", "GetMoneyRequest",  null, true, NULL);
        return cacheMoney;
    }

    static bool CheckifPlayerHasEnoughMoney(PlayerBase player, int price, int id, out int playerMoneyAmount)
    {
        GetPlayerMoney(player, id);
        playerMoneyAmount = cacheMoney;
        if(playerMoneyAmount < price){
            return false;
        }
            
        return true;
    }

    static bool RemoveMoneyFromPlayer(PlayerBase player, int moneyamount, int id)
    {
        Print("RemoveMoneyFromPlayer");
        KR_JsonDatabaseHandler targetdata = KR_JsonDatabaseHandler.LoadPlayerData(player.GetIdentity().GetPlainId(),  player.GetIdentity().GetName());
        
        if(targetdata.GetBankCredit() < moneyamount) {
            return false;
        }else{
            targetdata.WitdrawMoney( moneyamount );
            return true;
        }
    }
    
    static bool AddMoneyToPlayer(PlayerBase player, int amount, int id)
    {
        Print("AddMoneyToPlayer");
        KR_JsonDatabaseHandler targetdata = KR_JsonDatabaseHandler.LoadPlayerData(player.GetIdentity().GetPlainId(),  player.GetIdentity().GetName());
        targetdata.DepositMoney( amount );
        return true;
    }
    
}