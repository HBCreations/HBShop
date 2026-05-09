modded class MissionGameplay extends MissionBase
{
	void MissionGameplay()
	{
		m_TPCarryOnCore = NULL;
		GetTPCarryOnCore();
	}

	override void OnUpdate( float timeslice )
	{
			super.OnUpdate(timeslice);
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

			if ( !player.IsInVehicle() && !player.GetBleedingManagerRemote().GetBleedingSourceCountRemote() && !GetUIManager().GetMenu() && GetUApi().GetInputByName("ButtonPu").LocalPress() )
					GetRPCManager().SendRPC("TPCarryOn", "NormalTraderRequest",  NULL, true, NULL);

			if ( !player.IsInVehicle() && !player.GetBleedingManagerRemote().GetBleedingSourceCountRemote() && !GetUIManager().GetMenu() && GetUApi().GetInputByName("ButtonVIP").LocalPress() )
						GetRPCManager().SendRPC("TPCarryOn", "VIPTraderRequest",  NULL, true, NULL);
	}
};

modded class MissionServer extends MissionBase
{
	void MissionServer()
	{
		m_TPCarryOnCore = NULL;
		GetTPCarryOnCore();
	}
};
