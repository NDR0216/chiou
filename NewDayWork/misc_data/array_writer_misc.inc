<%
'�u�@�H���}�Cmisc_data.mdb writer_table
dim writer_a()
%>
<%
' �s��Access��Ʈwmisc_data.mdb
DBpath_a=Server.MapPath("./misc_data.mdb")
strCon_a="Driver={Microsoft Access Driver (*.mdb)};DBQ="&DBpath_a
'�إ߸�Ʈw�s������
set conDB_a= Server.CreateObject("ADODB.Connection")
'�s����Ʈw	
conDB_a.Open strCon_a
'�}�Ҹ�ƪ��W��
tb_name_a="writer_table"
%>
<%
'�إ߸�Ʈw�s������	
set rstObj_a=Server.CreateObject("ADODB.Recordset")
strSQL_a="Select * from " & tb_name_a 
rstObj_a.open strSQL_a,conDB_a,3
'�p�����`��	
writer_no=rstObj_a.recordcount
'���]�}�C�ƥ�
redim writer_a(Cint(writer_no))
rstObj_a.MoveFirst
for i=1 to writer_no
	writer_a(i-1)=rstObj_a.fields("writer")
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


	