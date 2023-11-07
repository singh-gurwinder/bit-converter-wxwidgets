#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP
#include "wxcrafter.hpp"
#include <bitset>
#include <iostream>

class MainFrame : public MainFrameBaseClass
{
public:
    MainFrame(wxWindow* parent);
    virtual ~MainFrame();
protected:
    virtual void OnSpinCtrl(wxCommandEvent& event);
    virtual void OnAbout(wxCommandEvent& event);
    virtual void OnExit(wxCommandEvent& event);
private:
    std::string toBinary(int value)
    {
        if (value > 0)
            return std::bitset<64>(value).to_string().substr(64 - (int)(log2(value)) - 1);
        else
            return "0";
    }
};
#endif // MAINFRAME_HPP
