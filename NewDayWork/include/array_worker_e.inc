<%
'�u�@�H���}�Cdaywork.mdb worker_data
dim eworker_a()
%>
<%
' �s��Access��Ʈwdaywork.mdb
DBpath_a=Server.MapPath("./database/daywork.mdb")
strCon_a="Driver={Microsoft Access Driver (*.mdb)};DBQ="&DBpath_a
'�إ߸�Ʈw�s������
set conDB_a= Server.CreateObject("ADODB.Connection")
'�s����Ʈw	
conDB_a.Open strCon_a
'�}�Ҹ�ƪ��W��
tb_name_a="worker_data"
%>
<%
'�إ߸�Ʈw�s������	
set rstObj_a=Server.CreateObject("ADODB.Recordset")
strSQL_a="Select * from " & tb_name_a 
rstObj_a.open strSQL_a,conDB_a,3
'�p�����`��	
eworker_no=rstObj_a.recordcount
'���]�}�C�ƥ�
redim eworker_a(Cint(eworker_no))
rstObj_a.MoveFirst
for i=1 to eworker_no
	eworker_a(i-1)=rstObj_a.fields("e_name")
'����U�@���O��		
	rstObj_a.MoveNext		
next
'������ƶ�
rstObj_a.Close
'���]����ܼ� 
set rstObj_a=Nothing
'������Ʈw 
conDB_a.Close
'���]�����ܼ� 
set conDB_a=Nothing 
%>


	