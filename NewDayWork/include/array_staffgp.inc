<%
'�s�հ}�C staffgp_a()
dim staffgp_a()
' �s��Access��Ʈw../holiday/database/crew.mdb
DBpath_acr=Server.MapPath("../holiday/database/crew.mdb")
strCon_acr="Driver={Microsoft Access Driver (*.mdb)};DBQ="&DBpath_acr
'�إ߸�Ʈw�s������
set conDB_acr= Server.CreateObject("ADODB.Connection")
'�s����Ʈw	
conDB_acr.Open strCon_acr
'�}�Ҹ�ƪ��W��
tb_name_acr="wk_sgp"
'�إ߸�Ʈw�s������	
set rstObj_acr=Server.CreateObject("ADODB.Recordset")
strSQL_acr="Select * from " & tb_name_acr &" order by gp_item asc"
rstObj_acr.open strSQL_acr,conDB_acr,1,3
'�p�����`��	
staff_no=rstObj_acr.recordcount
'���]�}�C�ƥ�
redim staffgp_a(Cint(staff_no))
rstObj_acr.MoveFirst
for icr=1 to staff_no
	staffgp_a(icr-1)=rstObj_acr.fields("gp_item") '�s��
'����U�@���O��		
	rstObj_acr.MoveNext		
next
'������ƶ�
rstObj_acr.Close
'���]����ܼ� 
set rstObj_acr=Nothing
'������Ʈw 
conDB_acr.Close
'���]�����ܼ� 
set conDB_acr=Nothing
%>