#ifndef BITPANE_HPP
#define BITPANE_HPP
#include <wx/wx.h>

#include <wx/graphics.h>
#include <wx/dcbuffer.h>

class BitPane : public wxWindow
{
public:
    BitPane(wxWindow *parent, char c, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition,
        const wxSize &size = wxDefaultSize);

    wxSize DoGetBestSize() const override
    {
        return FromDIP(wxSize(20,30));
    }
    
    void SetValue(char value)
    {
        this->value = value;
    }
    
private:
    char value;
    void OnPaint(wxPaintEvent &event);
};

BitPane::BitPane(wxWindow *parent, char c, wxWindowID id, const wxPoint &pos, const wxSize &size)
    : wxWindow(parent, id, pos, size, wxFULL_REPAINT_ON_RESIZE), value(c)
{
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &BitPane::OnPaint, this);
}

void BitPane::OnPaint(wxPaintEvent &event)
{
    wxUnusedVar(event);
    wxAutoBufferedPaintDC dc(this);
    dc.SetBackground(wxBrush(this->GetParent()->GetBackgroundColour()));
    dc.Clear();
    
    auto gc = wxGraphicsContext::Create(dc);
    if (gc)
    {
        wxRect contentRect{0, 0, this->GetSize().GetWidth(), this->GetSize().GetHeight()};
        contentRect.Deflate(FromDIP(1));
        gc->SetPen(*wxBLACK_PEN);
        
        if (value == '1')
        {
            gc->SetBrush(*wxBLACK_BRUSH);
            gc->DrawRectangle(contentRect.GetX(), contentRect.GetY(), contentRect.GetWidth(),
                contentRect.GetHeight());
        }
        else
        {
            gc->SetBrush(*wxTRANSPARENT_BRUSH);
            gc->DrawRectangle(contentRect.GetX(), contentRect.GetY(), contentRect.GetWidth(),
                contentRect.GetHeight());
        }
        delete gc;
    }
}
#endif // BITPANE_HPP