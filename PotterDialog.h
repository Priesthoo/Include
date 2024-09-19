#include<wx/dialog.h>
#include<wx/statline.h>
#include<wx/button.h>
#include<wx/stattext.h>
#include<wx/sizer.h>
#include<wx/textctrl.h>
#include<wx/spinctrl.h>
#include<wx/checkbox.h>
#include<wx/fontpicker.h>
#include<wx/clrpicker.h>
#ifndef DIALOG_H
#define DIALOG_H
#endif 
//These are the unique identifiers that will be used to identify the wxControl within the wxWindow.....
const int c=29;
const int c1=30;
const int c2=31;
const int c3=32;
const int c4=33;
const int sp=34;
const int sp1=35;
const int crl=36; 
const int b1=37;
const int cp1=38;
class MessageBus:public wxDialog{
    

};
class TextPosDialog:public wxDialog{
  private:
  wxTextAttr attr;
  int sptrlvalue;
  int sptrlvalue1;
  wxTextCtrl* tcrl;


  void SetTextAttr(const wxTextAttr& attr1 ){
    this->attr=attr1;
  }
  void SetSpinCtrlValue(const int& value){
    this->sptrlvalue=value;
  }
  void SetSpinCtrlValue1(const int& value){
    this->sptrlvalue1=value;
  }
  
  void OK(wxCommandEvent& evt){
    InitAllValue();
    EndModal(wxID_OK);
    return;
  }
  
  public:
  TextPosDialog(wxWindow* parent,const wxTextAttr& myattr,const int& a,const int& a0):wxDialog(parent,wxID_ANY,wxT("Text Alignment"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
     
     SetBackgroundColour(wxColour(240,240,240));
     CreateControls(myattr,a,a0);
     Show(true);
    ShowModal();
     this->Bind(wxEVT_BUTTON,&OK,this,wxID_OK);
  }
 void CreateControls(const wxTextAttr& attr,const int a,const int a0){
    wxStaticText* stext=new wxStaticText(this,wxID_ANY,wxT("Align Text"),wxDefaultPosition,wxDefaultSize);
    wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("Range of Text"),wxDefaultPosition,wxDefaultSize);
    wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("StartPos:"));
    wxStaticText* stext3=new wxStaticText(this,wxID_ANY,wxT("EndPos: "));
    wxStaticText* stext4=new wxStaticText(this,wxID_ANY,wxT("Preview:"));
    wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticLine* sline1=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticLine* sline2=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxCheckBox* cbox=new wxCheckBox(this,c,wxT("Align Left"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
    wxCheckBox* cbox1=new wxCheckBox(this,c1,wxT("Align right"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
    wxCheckBox* cbox2=new wxCheckBox(this,c2,wxT("Align Center"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
    wxCheckBox* cbox3=new wxCheckBox(this,c3,wxT("Align Justified"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE); 
    wxSpinCtrl* spctrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000,0);
    wxSpinCtrl* spctrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000,0);
    spctrl->SetValue(a);
    spctrl1->SetValue(a0);
    wxTextAttr textattr;
    textattr.SetAlignment(attr.GetAlignment());
    wxTextCtrl* textctrl=new wxTextCtrl;
    if(textattr.GetAlignment()==wxTEXT_ALIGNMENT_LEFT){
        textctrl->Create(this,c4,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_LEFT|wxTE_MULTILINE|wxHSCROLL);
    }
    else if(textattr.GetAlignment()==wxTEXT_ALIGNMENT_RIGHT){
        textctrl->Create(this,c4,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_RIGHT|wxTE_MULTILINE|wxHSCROLL);
    }
    else if(textattr.GetAlignment()==wxTEXT_ALIGNMENT_CENTER){
        textctrl->Create(this,c4,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_CENTER|wxTE_MULTILINE|wxHSCROLL);
    }
    else{
       textctrl->Create(this,c4,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_MULTILINE|wxHSCROLL);
    } 
    textctrl->AppendText(wxT("Grace Of God"));
    wxTextAttr txtattr;
    txtattr.SetAlignment(attr.GetAlignment());
    if(txtattr.GetAlignment()==wxTEXT_ALIGNMENT_LEFT){
      cbox->SetValue(true);
      cbox1->SetValue(false);
      cbox2->SetValue(false);
      cbox3->SetValue(false);
    }
    else if(txtattr.GetAlignment()==wxTEXT_ALIGNMENT_CENTER){
      cbox->SetValue(false);
      cbox1->SetValue(false);
      cbox2->SetValue(true);
      cbox3->SetValue(false);
    }
    else if(txtattr.GetAlignment()==wxTEXT_ALIGNMENT_RIGHT){
      cbox->SetValue(false);
      cbox1->SetValue(true);
      cbox2->SetValue(false);
      cbox3->SetValue(false);
    }
    else if(txtattr.GetAlignment()==wxTEXT_ALIGNMENT_JUSTIFIED){
      cbox->SetValue(false);
      cbox1->SetValue(false);
      cbox2->SetValue(false);
      cbox3->SetValue(true);
    }
    

    wxButton* bton= new wxButton(this,wxID_OK,wxT("&Ok"));
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);   
    SetSizer(bsizer);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer4=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer5=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer6=new wxBoxSizer(wxHORIZONTAL);
    bsizer->Add(bsizer1,0,wxLEFT,5);
    bsizer1->Add(stext,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(10,10,0,wxALIGN_CENTER_HORIZONTAL|wxALL,0);
    bsizer->Add(bsizer2,0,wxLEFT,10);
    bsizer2->Add(cbox,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(20,20,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(cbox1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(10,10,0,wxALIGN_CENTER_HORIZONTAL|wxALL,0);
    bsizer->Add(bsizer3,0,wxLEFT,10);
    bsizer3->Add(cbox2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(20,20,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(cbox3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,5);
    bsizer->Add(bsizer4,0,wxLEFT|wxALL,5);
    bsizer4->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer4->Add(sline1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(bsizer5,0,wxLEFT|wxALL,10);
    bsizer5->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(spctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(stext3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(spctrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT,5);
    bsizer->Add(bsizer6,0,wxLEFT,5);
    bsizer6->Add(stext4,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer6->Add(sline2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT,0);
    bsizer->Add(textctrl,0,wxLEFT|wxALL,10);
    bsizer->Add(bton,0,wxRIGHT|wxALL,5);
    
}
wxTextAttr GetTextAttr() const{
   return attr;
}
int GetSpinCtrlValue() const {
   return sptrlvalue;
} 
 int GetSpinCtrlValue1() const {
    return sptrlvalue1;
 }
void InitAllValue(){
    wxCheckBox* cbox=(wxCheckBox*)FindWindow(c);
    wxCheckBox* cbox1=(wxCheckBox*)FindWindow(c1);
    wxCheckBox* cbox2=(wxCheckBox*)FindWindow(c2);
    wxCheckBox* cbox3=(wxCheckBox*)FindWindow(c3);
    wxSpinCtrl* spinctrl=(wxSpinCtrl*)FindWindow(sp);
    wxSpinCtrl* spinctrl1=(wxSpinCtrl*)FindWindow(sp1);
    wxTextCtrl* ctrl=(wxTextCtrl*)FindWindow(c4);
    if((cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked())){
       attr.SetAlignment(wxTEXT_ALIGNMENT_LEFT);
       sptrlvalue=spinctrl->GetValue();
       sptrlvalue1=spinctrl1->GetValue();
       return;
    }
     if((cbox1->IsChecked()) && !(cbox->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked())){
       attr.SetAlignment(wxTEXT_ALIGNMENT_RIGHT);
       sptrlvalue=spinctrl->GetValue();
       sptrlvalue1=spinctrl1->GetValue();
       return;
    }
     if((cbox2->IsChecked()) && !(cbox1->IsChecked()) && !(cbox->IsChecked()) && !(cbox3->IsChecked())){
       attr.SetAlignment(wxTEXT_ALIGNMENT_CENTER);
       sptrlvalue=spinctrl->GetValue();
       sptrlvalue1=spinctrl1->GetValue();
       return;
    }
     if((cbox3->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox->IsChecked())){
       attr.SetAlignment(wxTEXT_ALIGNMENT_JUSTIFIED);
       sptrlvalue=spinctrl->GetValue();
       sptrlvalue1=spinctrl1->GetValue();
       return;
    }
}

};

class TextPosFontDialog: public wxDialog{
   private:
   wxTextAttr attr;
   int Sptrlvalue;
   int Sptrlvalue1;

   public:
    wxTextAttr GetTextAttr() const{
    return attr;
    }
    int GetSptrlvalue() const{
    return Sptrlvalue;
    }
    int GetSptrlvalue1() const{
    return Sptrlvalue1;
    }
   void OkPressed(wxCommandEvent& evt){
    InitAllValues();
    EndModal(wxID_OK);
    return;
   }
   
//Constructor For TextPosFontDialog
   TextPosFontDialog(wxWindow* parent,wxFontPickerCtrl* tcrl,const int& a,const int& a0):wxDialog(parent,wxID_ANY,wxT("Apply Positional Fonts"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
     
     SetBackgroundColour(wxColour(240,240,240));
     CreateControls(tcrl,a,a0);
     Show(true);
     ShowModal();
     Bind(wxEVT_BUTTON,&OkPressed,this,wxID_OK);
   }
   void CreateControls(wxFontPickerCtrl* font,const int& a,const int& a0){
    wxStaticText* stext=new wxStaticText(this,wxID_ANY,wxT("Apply Font attributes to range of position"));
    wxStaticText* stext0=new wxStaticText(this,wxID_ANY,wxT("Range of Text"));
    wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("StartPos:"));
    wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("EndPos:"));
    wxStaticText* stext3=new wxStaticText(this,wxID_ANY,wxT("Preview:"));
    wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticLine* sline1=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxTextCtrl* tcrl=new wxTextCtrl(this,crl,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_MULTILINE|wxTE_RICH|wxHSCROLL);
    wxSpinCtrl* spctrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000000,0);
    wxSpinCtrl* spctrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000000,0);
    wxStaticText* st=new wxStaticText(this,wxID_ANY,wxT("Font Picker:"));
    wxFontPickerCtrl* button=new wxFontPickerCtrl(this,b1);
    wxButton* button1=new wxButton(this,wxID_OK,wxT("Ok"));
    spctrl->SetValue(a);
    spctrl1->SetValue(a0);
    wxTextAttr attr1;
    attr1.SetFont(font->GetSelectedFont());
    attr1.SetTextColour(font->GetSelectedColour());
    tcrl->SetDefaultStyle(attr1);
    button->SetSelectedFont(font->GetSelectedFont());
    button->SetSelectedColour(font->GetSelectedColour());
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer4=new wxBoxSizer(wxHORIZONTAL);
    SetSizer(bsizer);
    bsizer->Add(stext,0,wxLEFT|wxALL,10);
    bsizer->Add(10,10,0,wxLEFT,0);
    bsizer->Add(bsizer1,0,wxLEFT|wxALL,10);
    bsizer1->Add(stext0,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer2,0,wxLEFT,10);
    bsizer2->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(spctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(spctrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT,0);
    bsizer->Add(bsizer4,0,wxLEFT|wxALL,5);
    bsizer4->Add(st,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer4->Add(button,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(bsizer3,0,wxLEFT,5);
    bsizer3->Add(stext3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(sline1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(tcrl,0,wxLEFT|wxALL,5);
    bsizer->Add(button1,0,wxRIGHT|wxALL,10);
    tcrl->AppendText(wxT("Grace Of God"));
    }
void InitAllValues(){
  wxSpinCtrl* sptrl=(wxSpinCtrl*)FindWindow(sp);
  wxSpinCtrl* sptrlone=(wxSpinCtrl*)FindWindow(sp1);
    Sptrlvalue=sptrl->GetValue();
  Sptrlvalue1=sptrlone->GetValue();
   wxFontPickerCtrl* fontpicker=(wxFontPickerCtrl*)FindWindow(b1);
      wxTextCtrl* tcrl=(wxTextCtrl*)FindWindow(crl);
      attr.SetFont(fontpicker->GetSelectedFont());
     attr.SetTextColour(fontpicker->GetSelectedColour());
     tcrl->SetDefaultStyle(attr);
  return;  
}
};
class TextUnderlinedDialog:public wxDialog{
private:
  int a2;
  int a3;
  wxTextAttr textattr;
  void Ok(wxCommandEvent& evt){
   InitAllValues(textattr);
   EndModal(wxID_OK);
  }
public:
  TextUnderlinedDialog(wxWindow*parent,const wxTextAttr& attr,const int& a,const int& a0):wxDialog(parent,wxID_ANY,wxT("Underline Style"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
   CreateControls(attr,a,a0);
   Show(true);
   ShowModal();
   Bind(wxEVT_BUTTON,&Ok,this,wxID_OK);
  }
  void CreateControls(const wxTextAttr& attr,const int& a,const int& a0){
   wxStaticText*stext=new wxStaticText(this,wxID_ANY,wxT("Apply Underline style to a range of position"));
   wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("Types of Underline Style"));
   wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("Range of Pos:"));
   wxStaticText* stext3=new wxStaticText(this,wxID_ANY,wxT("StartPos:"));
   wxStaticText* stext4=new wxStaticText(this,wxID_ANY,wxT("EndPos:"));
   wxStaticText* stext5=new wxStaticText(this,wxID_ANY,wxT("Preview:"));
   wxStaticText* stext6=new wxStaticText(this,wxID_ANY,wxT("Underline Colour:"));
   wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
   wxStaticLine* sline1=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
   wxStaticLine* sline2=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
   wxCheckBox* cbox=new wxCheckBox(this,c,wxT("Double"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
   wxCheckBox* cbox1=new wxCheckBox(this,c1,wxT("Solid"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
   wxCheckBox* cbox2=new wxCheckBox(this,c2,wxT("None"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
   wxCheckBox* cbox3=new wxCheckBox(this,c3,wxT("Special"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
   wxSpinCtrl* spctrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000000,0);
   wxSpinCtrl* spctrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000000,0);
   spctrl->SetValue(a);
   spctrl1->SetValue(a0);
    wxTextAttr tatrr;
   tatrr.SetFont(attr.GetFont());
   textattr.SetFont(attr.GetFont());
   tatrr.SetFontUnderlined(attr.GetUnderlineType(),attr.GetUnderlineColour());

    if(tatrr.GetUnderlineType()==wxTEXT_ATTR_UNDERLINE_DOUBLE){
      cbox->SetValue(true);
      cbox1->SetValue(false);
      cbox2->SetValue(false);
      cbox3->SetValue(false);
    }
    else if(tatrr.GetUnderlineType()==wxTEXT_ATTR_UNDERLINE_NONE){
      cbox->SetValue(false);
      cbox1->SetValue(false);
      cbox2->SetValue(true);
      cbox3->SetValue(false);
    }
    else if(tatrr.GetUnderlineType()==wxTEXT_ATTR_UNDERLINE_SOLID){
      cbox->SetValue(false);
      cbox1->SetValue(true);
      cbox2->SetValue(false);
      cbox3->SetValue(false);
    }
    else if(tatrr.GetUnderlineType()==wxTEXT_ATTR_UNDERLINE_SPECIAL){
      cbox->SetValue(false);
      cbox1->SetValue(false);
      cbox2->SetValue(false);
      cbox3->SetValue(true);
    }
   wxTextCtrl* tcrl=new wxTextCtrl(this,crl,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_MULTILINE|wxTE_RICH|wxHSCROLL);
   wxColourPickerCtrl* cptrl=new wxColourPickerCtrl(this,cp1);
   tcrl->SetDefaultStyle(tatrr);

   tcrl->AppendText(wxT("Glory To God For Grace"));
   wxButton* bton=new wxButton(this,wxID_OK,wxT("Ok"));

   cptrl->SetColour(tatrr.GetUnderlineColour());
   wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
   wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer4=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer5=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer6=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer7=new wxBoxSizer(wxHORIZONTAL);
   SetSizer(bsizer);
   bsizer->Add(stext,0,wxLEFT|wxALL,10);
   bsizer->Add(bsizer1,0,wxLEFT|wxALL,10);
   bsizer1->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,5);
   bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(10,10,0,wxLEFT|wxALL,0);
   bsizer->Add(bsizer2,0,wxLEFT|wxALL,10);
   bsizer2->Add(cbox,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer2->Add(10,10,0,wxALIGN_CENTER_VERTICAL,10);
   bsizer2->Add(cbox1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(5,5,0,wxLEFT|wxALL,0);
   bsizer->Add(bsizer3,0,wxLEFT|wxALL,10);
   bsizer3->Add(cbox2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer3->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,10);
   bsizer3->Add(cbox3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(bsizer4,0,wxLEFT|wxALL,5);
   bsizer4->Add(stext6,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer4->Add(cptrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(bsizer5,0,wxLEFT|wxALL,5);
   bsizer5->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer5->Add(sline1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(10,10,0,wxLEFT|wxALL,0);
   bsizer->Add(bsizer6,0,wxLEFT|wxALL,10);
   bsizer6->Add(stext3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer6->Add(spctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer6->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer6->Add(stext4,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer6->Add(spctrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(bsizer7,0,wxLEFT,5);
   bsizer7->Add(stext5,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer7->Add(sline2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(tcrl,0,wxLEFT|wxALL,5);
   bsizer->Add(10,10,0,wxLEFT|wxALL,0);
   bsizer->Add(bton,0,wxLEFT|wxALL,5);
   
   return;
  }
  int GetOne() const{
   return a2;
  }
  int Gettwo() const{
   return a3;
  }
  wxTextAttr GetCurrentTextAttr() const{
   return textattr;
  }
  
   void InitAllValues(const wxTextAttr& att){
    wxCheckBox* cbox=(wxCheckBox*)FindWindow(c);
    wxCheckBox* cbox1=(wxCheckBox*)FindWindow(c1);
    wxCheckBox* cbox2=(wxCheckBox*)FindWindow(c2);
    wxCheckBox* cbox3=(wxCheckBox*)FindWindow(c3);
    wxSpinCtrl* spinctrl=(wxSpinCtrl*)FindWindow(sp);
    wxSpinCtrl* spinctrl1=(wxSpinCtrl*)FindWindow(sp1);
    wxColourPickerCtrl* ctrl=(wxColourPickerCtrl*)FindWindow(cp1);
    if((cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked())){
      textattr.SetFont(att.GetFont());
      textattr.SetFontUnderlined(wxTEXT_ATTR_UNDERLINE_DOUBLE,ctrl->GetColour());
       a2=spinctrl->GetValue();
       a3=spinctrl1->GetValue();
       return;
    }
     if((cbox1->IsChecked()) && !(cbox->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked())){
       textattr.SetFont(att.GetFont());
       textattr.SetFontUnderlined(wxTEXT_ATTR_UNDERLINE_SOLID,ctrl->GetColour());
       a2=spinctrl->GetValue();
       a3=spinctrl1->GetValue();
       return;
    }
     if((cbox2->IsChecked()) && !(cbox1->IsChecked()) && !(cbox->IsChecked()) && !(cbox3->IsChecked())){
       textattr.SetFont(att.GetFont());
       textattr.SetFontUnderlined(wxTEXT_ATTR_UNDERLINE_NONE,ctrl->GetColour());
       a2=spinctrl->GetValue();
       a3=spinctrl1->GetValue();
       return;
    }
     if((cbox3->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox->IsChecked())){
       textattr.SetFont(att.GetFont());
       textattr.SetFontUnderlined(wxTEXT_ATTR_UNDERLINE_SPECIAL,ctrl->GetColour());
       a2=spinctrl->GetValue();
       a3=spinctrl1->GetValue();
       return;
    }
}

};

