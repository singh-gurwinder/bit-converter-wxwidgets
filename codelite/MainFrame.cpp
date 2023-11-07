#include "MainFrame.hpp"
#include "BitPane.hpp"
#include <wx/aboutdlg.h>

MainFrame::MainFrame(wxWindow* parent)
    : MainFrameBaseClass(parent)
{
}

MainFrame::~MainFrame()
{
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxUnusedVar(event);
    wxAboutDialogInfo info;
    info.SetCopyright(_("Bit Converter"));
    info.SetLicence(_("GPL v2 or later"));
    info.SetDescription(_("Decimal number to bit converter."));
    ::wxAboutBox(info);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    wxUnusedVar(event);
    Close();
}

void MainFrame::OnSpinCtrl(wxCommandEvent& event)
{
    wxUnusedVar(event);
    std::string binaryString = toBinary(m_numberSpinCtrl->GetValue());
    m_binaryStaticText->SetLabel(wxString::Format(wxT("Binary: %s"), binaryString));
    boxSizerBitPanel->Clear(true);
    for (const char c : binaryString)
    {
        auto bitPanel = new BitPane(m_bitPanel, c);
        boxSizerBitPanel->Add(bitPanel, 0, wxRIGHT | wxBOTTOM, FromDIP(5));
    }
    m_bitPanel->Refresh();
    m_bitPanel->Layout();
    m_bitPanel->Update();
}

