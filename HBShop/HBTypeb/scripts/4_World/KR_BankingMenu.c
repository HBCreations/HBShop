modded class KR_BankingMenu
{
    override Widget Init()
    {
        if(!m_IsBankingMenuInitialized)
        {
            layoutRoot                      = GetGame().GetWorkspace().CreateWidgets("HBShop/HBTypeb/GUI/layouts/BankingMenu.layout");
            m_OwnBankAccountTab             = Widget.Cast(layoutRoot.FindAnyWidget("PanelBankAcc"));
            m_ClanBankAccountTab            = Widget.Cast(layoutRoot.FindAnyWidget("PanelClanAcc"));
            m_TransferTab                   = Widget.Cast(layoutRoot.FindAnyWidget("PDABodyTransfer"));
            m_YesNoMessage                  = Widget.Cast(layoutRoot.FindAnyWidget("PanelYesNoMsg"));
            m_ClanSettings                  = Widget.Cast(layoutRoot.FindAnyWidget("PanelClanSettings"));
            m_PanelAdmin                    = Widget.Cast(layoutRoot.FindAnyWidget("PanelAdmin"));
            m_PanelPerms                    = Widget.Cast(layoutRoot.FindAnyWidget("PanelPerms"));
            m_PanelNewClan                  = Widget.Cast(layoutRoot.FindAnyWidget("PanelNewClan"));
            m_PanelNewClanPrice             = Widget.Cast(layoutRoot.FindAnyWidget("PanelNewClanPrice"));
            m_PanelName                     = Widget.Cast(layoutRoot.FindAnyWidget("PanelWidgetName"));
            m_LeaveConfirm                  = Widget.Cast(layoutRoot.FindAnyWidget("PanelLeaveConfirm"));
            m_OwnersPanel                   = Widget.Cast(layoutRoot.FindAnyWidget("PanelOwner"));

            m_CloseUiBtn                    = ButtonWidget.Cast(layoutRoot.FindAnyWidget("CloseInvi"));
            m_BankAccBtn                    = ButtonWidget.Cast(layoutRoot.FindAnyWidget("BtnTabBank"));
            m_ClanAccBtn                    = ButtonWidget.Cast(layoutRoot.FindAnyWidget("BtnTabClanBank"));
            m_WithdrawOwnAccBtn             = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnWitdraw"));
            m_WithdrawClan                  = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnWitdrawClan"));
            m_DepositOwnAccBtn              = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnDeposit"));
            m_DepositClanAccbtn             = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnDepositClan"));
            m_TransferBtn                   = ButtonWidget.Cast(layoutRoot.FindAnyWidget("BtnTabTransfer"));
            m_YesConfirmBtn                 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonWidget3"));
            m_NoConfirmBtn                  = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonWidget2"));
            m_BtnClanSettings               = ButtonWidget.Cast(layoutRoot.FindAnyWidget("BtnClanSettings"));
            m_BtnKick                       = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonKick"));
            m_BtnAdd                        = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonEdit0"));
            m_BtnBack                       = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonBack"));
            m_BtnSave                       = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonWidget0"));
            m_BtnSendTransfer               = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnSend"));
            m_BtnFinallyCreate              = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonWidgetCreate"));
            m_BtnYesCreate                  = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonWidget1"));
            m_BtnLeaveClan                  = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonLeave"));
            m_BtnLeaveYes                   = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonLeaveYes"));
            m_BtnLeaveNo                    = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonLeaveNo"));
            m_BtnOwnerSafeBtn               = ButtonWidget.Cast(layoutRoot.FindAnyWidget("BtnSave"));

            m_OwnAccInputBox                = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("EditBoxWidget0"));
            m_TransferInputBox              = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("EditBoxWidget1"));
            m_ClanAccInputBox               = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("InputBoxClan"));
            m_EditBoxClanName               = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("EditBoxWidgetName"));
            m_EditBoxClanTag                = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("EditBoxWidgetTag"));
            m_EditBoxClanNameOwner          = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("txtBoxClanName"));
            m_EditBoxClanTagOwner           = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("txtBoxClanTag"));


            m_OwnedCurrencyLabel            = TextWidget.Cast(layoutRoot.FindAnyWidget("BankAmountValueText"));
            m_OnPlayerCurrencyLabel         = TextWidget.Cast(layoutRoot.FindAnyWidget("TextCashOnPlayer"));
            m_PriceToCreate                 = TextWidget.Cast(layoutRoot.FindAnyWidget("TextWidgetPrice"));
            m_OnPlayerCurrencyLabel2        = TextWidget.Cast(layoutRoot.FindAnyWidget("BankAmountValueText0"));
            m_ProgressText                  = TextWidget.Cast(layoutRoot.FindAnyWidget("TextWidgetPercentage"));
            m_CurrentProgressMinTxt         = TextWidget.Cast(layoutRoot.FindAnyWidget("TextWidgetCurrent"));
            m_CurrentMaxProgressTxt         = TextWidget.Cast(layoutRoot.FindAnyWidget("TextWidgetMax"));
            m_ProgressTextClan              = TextWidget.Cast(layoutRoot.FindAnyWidget("TextWidgetPercentage0"));
            m_CashOnPlayer                  = TextWidget.Cast(layoutRoot.FindAnyWidget("TextCashOnPlayer0"));
            m_ClanAmount                    = TextWidget.Cast(layoutRoot.FindAnyWidget("BankClanAmmount"));

            m_YesNoMsgHeadline              = MultilineTextWidget.Cast(layoutRoot.FindAnyWidget("TextHeadline0"));
            m_YesNoMsgBody                  = MultilineTextWidget.Cast(layoutRoot.FindAnyWidget("TextMessage0"));

            m_ListboxMember                 = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("TextListboxMember"));
            m_ListboxPlayers                = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("TextListboxPlayers"));
            m_TransferPlayerList            = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("TextListboxWidget0"));
            m_ClanLogs                      = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("TextListboxLogs"));

            m_CheckBoxWithdraw              = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("CheckBoxWithdraw"));
            m_CheckBoxDeposit               = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("CheckBoxDeposit")); 
            m_CheckBoxKick                  = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("CheckBoxKick"));
            m_CheckBoxAdd                   = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("CheckBoxInvite"));
            m_CheckBoxPermissions           = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("CheckBoxPermission"));

            m_OwnBankAccountProgressbar     = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("ProgressBarWidget0"));
            m_ClanBankAccountProgressbar    = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("ProgressBarWidgetClan"));


            m_IsBankingMenuInitialized = true;
        }

        return layoutRoot;
    }
};