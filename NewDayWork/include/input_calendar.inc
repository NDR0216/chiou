<!--��䲣�ͪ���m-->
<Span ID=ShowCal style="position:absolute;z-index:1"></Span>

<Script Language=VBScript>

sub Cal(TObject)

'���ͤ��A�H���Ѫ���������
nYear=Year(Now())
nMonth=Month(Now())
 GetCal nYear,nMonth,TObject

'�վ�<Span>����m
 ShowCal.style.left=window.event.clientX
 ShowCal.style.top=window.event.clientY
End sub 

Sub GetCal(SYear,SMonth,TObject)
'�����Y����
Str=Str &"<table ALIGN='CENTER' BORDER='1' CELLSPACING='0' CELLPADDING='2' BGCOLOR='White' BORDERCOLOR='Gray'>"
Str=Str &"<tr><td>"
Str=Str &"        <table WIDTH='140' BORDER='0' CELLPADDING='1' CELLSPACING='0' BGCOLOR='#FFFFFF'>"
Str=Str &"                <tr HEIGHT='18' BGCOLOR='Silver'>"
Str=Str &"                        <td WIDTH='20' HEIGHT='18' ALIGN='LEFT' VALIGN='MIDDLE'><img SRC='img/prev3.gif' WIDTH='18' HEIGHT='18' BORDER='0' ALT='�W�@��' style='cursor:hand' OnClick='PreMon(""" & TObject & """)'></td>"
Str=Str &"                        <td WIDTH='20' HEIGHT='18' ALIGN='LEFT' VALIGN='MIDDLE'><img SRC='img/Next3.gif' WIDTH='18' HEIGHT='18' BORDER='0' ALT='�U�@��' style='cursor:hand' OnClick='NextMon(""" & TObject & """)'></td>"
Str=Str &"                        <td WIDTH='100' COLSPAN='4' ALIGN='CENTER' VALIGN='MIDDLE' CLASS='SOME'><Span ID=SelYear>" & SYear & "</span>�~<Span ID=SelMon>" & SMonth & "</Span>��</td>"
Str=Str &"                        <td WIDTH='20' HEIGHT='18' ALIGN='RIGHT' VALIGN='MIDDLE'><img SRC='img/cdia3.gif' WIDTH='18' HEIGHT='18' BORDER='0' ALT='��������' style='cursor:hand' OnClick='Closedate()'></td>"
Str=Str &"                </tr>"
Str=Str &"          <tr HEIGHT='15' BGCOLOR='Aliceblue'>"
Str=Str &"                <td Colspan=7>"
Str=Str &"                 <Table Border=0>"
Str=Str &"                  <tr>"
Str=Str &"                    <td ALIGN='RIGHT' CLASS='SOME' WIDTH='20' HEIGHT='15' VALIGN='BOTTOM'>��</td>"
Str=Str &"                    <td ALIGN='RIGHT' CLASS='SOME' WIDTH='20' HEIGHT='15' VALIGN='BOTTOM'>�@</td>"
Str=Str &"                    <td ALIGN='RIGHT' CLASS='SOME' WIDTH='20' HEIGHT='15' VALIGN='BOTTOM'>�G</td>"
Str=Str &"                    <td ALIGN='RIGHT' CLASS='SOME' WIDTH='20' HEIGHT='15' VALIGN='BOTTOM'>�T</td>"
Str=Str &"                    <td ALIGN='RIGHT' CLASS='SOME' WIDTH='20' HEIGHT='15' VALIGN='BOTTOM'>�|</td>"
Str=Str &"                    <td ALIGN='RIGHT' CLASS='SOME' WIDTH='20' HEIGHT='15' VALIGN='BOTTOM'>��</td>"
Str=Str &"                    <td ALIGN='RIGHT' CLASS='SOME' WIDTH='20' HEIGHT='15' VALIGN='BOTTOM'>��</td>"
Str=Str &"         </tr>"
Str=Str &"        </Table>"
Str=Str &"          </tr>"
Str=Str &"          <tr>"
Str=Str &"           <td HEIGHT='1' ALIGN='MIDDLE' COLSPAN='7'><img SRC='images/line.gif' HEIGHT='1' WIDTH='140' BORDER='0'></td>"
Str=Str &"          </tr>"
Str=Str &"      <tr>"

'�Ӥ�Ĥ@�Ѥ��P��
SDate=DateValue(SYear & "/" & SMonth & "/1")
SWeek=WeekDay(SDate)

'�Ӥ�̫�@�Ѫ����
EDay=Day(DateSerial(SYear,SMonth+1,0))
EDate=DateValue(SYear & "/" & SMonth & "/" & EDay)

'�Ӥ�̫�@�Ѥ��P��
EWeek=WeekDay(EDate)

'�W��̫�@�Ѫ����
PreEDay=Day(DateSerial(SYear,SMonth,0))

'���ͤW�Ӥ몺����
Dim i
For i=1 to SWeek-1
 Str=Str & "<td CLASS='myd' width=20 align=right><font color=gray>" & PreEDay-SWeek+i+1 & "</font></td>"
Next

If SWeek=1 then
 Str=Str & "</tr>"
End if

'���ͥ��볡��
SW=SWeek
i=1
For i=1 to EDay
 '�վ㤻��r�����C��
 Select Case SW
 Case 1
  FColor="Red"
 Case 7
  FColor="Green"
 Case Else
  FColor="Black"
 End Select
  
  GDate=SYear & "/" & SMonth & "/" & i
'  Str=Str & "<td CLASS='myd' width=20 align=right style='cursor:hand' onMouseOver=""this.style.backgroundColor='#FF99FF'"" onMouseOut=""this.style.backgroundColor='White'"" Onclick=""SendDate('" & GDate & "','" & TObject & "')""><Font Color=" & FColor & ">" & i & "</Font></td>"
  Str=Str & "<td CLASS='myd' width=20 align=right style='cursor:hand' onMouseOver=""this.style.backgroundColor='#FF99FF'"" onMouseOut=""this.style.backgroundColor='White'"" Onclick=""SendDate('" & GDate & "','" & TObject & "')""><Font Color=" & FColor & ">" & i & "</Font></td>"
 
'���ͤU�Ӥ볡��
SW=SW+1
 IF SW>7 then
  Str=Str & "</tr><tr>"
 SW=1
 End if
Next

J=1
For i=SW to 7
 Str=Str & "<td CLASS='myd' width=20 align=right><Font Color=Gray>" & j & "</Font></td>"
 J=j+1
Next


Str=Str & "      </tr>"
Str=Str & "</Table>"

'�N��ƤޤJ<Span>
ShowCal.InnerHTML=Str

End Sub

'�e���@�Ӥ�
Sub PreMon(TObject)
 SYear=Int(SelYear.OuterTEXT)
 SMon=int(SelMon.outerTEXT)-1

 '�P�_�O�_���e�դ@�~
 IF SMon<1 then
  SMon=12
  SYear=SYear-1
 End if
 Call GetCal(SYear,SMon,TObject)
End Sub

'�Ჾ�@�Ӥ�
Sub NextMon(TObject)
 SYear=Int(SelYear.OuterTEXT)
 SMon=int(SelMon.outerTEXT)+1

 '�P�_�O�_���e���@�~
 IF SMon>12 then
  SMon=1
  SYear=SYear+1
 End if
 GetCal SYear,SMon,TObject 
End Sub

'�N��ưe�J��줺
function SendDate(GDate,TObject)
 document.all.namedItem(TObject).Value=GDate
 ShowCal.InnerHTML=""
End function

'��������e��
Sub CloseDate()
 ShowCal.InnerHTML=""
End Sub
</Script>