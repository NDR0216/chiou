<%
'�u�@�H���}�Cdaywork.mdb worker_data
dim worker_a()
dim cworker_a()
dim eworker_a()
dim staff_a()
dim staff_gp_a()
dim staff_dp_a()
dim staff_id_a()
' �s��Access��Ʈwdaywork.mdb
DBpath_a1=Server.MapPath("./database/crew.mdb")
strCon_a1="Driver={Microsoft Access Driver (*.mdb)};DBQ="&DBpath_a1
'�إ߸�Ʈw�s������
set conDB_a1= Server.CreateObject("ADODB.Connection")
'�s����Ʈw	
conDB_a1.Open strCon_a1
'�}�Ҹ�ƪ��W��
tb_name_a1="crew"
'�إ߸�Ʈw�s������	
set rstObj_a1=Server.CreateObject("ADODB.Recordset")
'strSQL_a1="Select * from " & tb_name_a1 &" where hide = false order by wk_sgp asc, wk_gp_sq asc, wkr_id asc"
strSQL_a1="Select * from " & tb_name_a1 &" where hide = false order by wk_gp_sq asc"
rstObj_a1.open strSQL_a1,conDB_a1,3
'�p�����`��	
worker_no=rstObj_a1.recordcount
staff_no=rstObj_a1.recordcount
'���]�}�C�ƥ�
redim worker_a(Cint(worker_no))
redim cworker_a(Cint(worker_no))
redim eworker_a(Cint(worker_no))
'���]�}�C�ƥ�
redim staff_a(Cint(staff_no))
redim staff_gp_a(Cint(staff_no))
redim staff_dp_a(Cint(staff_no))
redim staff_id_a(Cint(staff_no))
rstObj_a1.MoveFirst
for i=1 to worker_no
	worker_a(i-1)=rstObj_a1.fields("worker")     '����W
	cworker_a(i-1)=rstObj_a1.fields("wkr_name")     '������W
	eworker_a(i-1)=rstObj_a1.fields("e_name")   '�^��W
	staff_id_a(i-1)=rstObj_a1.fields("wkr_id") 'id
	staff_a(i-1)=rstObj_a1.fields("e_name") '�ʺ�
	staff_gp_a(i-1)=rstObj_a1.fields("wk_sgp") '�s��
	staff_dp_a(i-1)=rstObj_a1.fields("wk_gp") '����	
'����U�@���O��		
	rstObj_a1.MoveNext		
next
'������ƶ�
rstObj_a1.Close
'���]����ܼ� 
set rstObj_a1=Nothing
'������Ʈw 
conDB_a1.Close
'���]�����ܼ� 
set conDB_a1=Nothing 

'======�����H���r��============
stra_dp01="" '�`�g�z��
stra_dp02="" '�޲z��
stra_dp03="" '������
stra_dp04="" '�~�ȳ�
stra_dp05="" '�k��+������
stra_dp06="" '�]�ȳ�
stra_dp07="" '��T+�޲z��
stra_dp08="" '�س]��
stra_dp09="" '��������|
stra_dp10="" '�ڮa�A�~

stra_dpa1="" '�~1
stra_dpa2="" '�~2
stra_dpa3="" '�~3
stra_dpa4="" '�~4
stra_dpa5="" '�~5

for ki=1 to worker_no

	if instr(1,staff_dp_a(ki-1),"�`�g�z��",1)>0 then
			if  stra_dp01="" then
				stra_dp01= worker_a(ki-1)
			else  
				stra_dp01= stra_dp01 & "," & worker_a(ki-1)
			end if
	end if
	if instr(1,staff_dp_a(ki-1),"�޲z��",1)>0 then
			if  stra_dp02="" then
				stra_dp02= worker_a(ki-1)
			else  
				stra_dp02= stra_dp02 & "," & worker_a(ki-1)
			end if
	end if
	if instr(1,staff_dp_a(ki-1),"������",1)>0 then
			if  stra_dp03="" then
				stra_dp03= worker_a(ki-1)
			else  
				stra_dp03= stra_dp03 & "," & worker_a(ki-1)
			end if
	end if
	if instr(1,staff_dp_a(ki-1),"�~�ȳ�",1)>0 then
			if  stra_dp04="" then
				stra_dp04= worker_a(ki-1)
			else  
				stra_dp04= stra_dp04 & "," & worker_a(ki-1)
			end if
	end if
	if instr(1,staff_dp_a(ki-1),"�k�ȳ�",1)>0 then
			if  stra_dp05="" then
				stra_dp05= worker_a(ki-1)
			else  
				stra_dp05= stra_dp05 & "," & worker_a(ki-1)
			end if
	end if
	if instr(1,staff_dp_a(ki-1),"�]�ȳ�",1)>0 then
			if  stra_dp06="" then
				stra_dp06= worker_a(ki-1)
			else  
				stra_dp06= stra_dp06 & "," & worker_a(ki-1)
			end if
	end if
	if instr(1,staff_dp_a(ki-1),"��T��",1)>0 then
			if  stra_dp07="" then
				stra_dp07= worker_a(ki-1)
			else  
				stra_dp07= stra_dp07 & "," & worker_a(ki-1)
			end if
	end if
	if instr(1,staff_dp_a(ki-1),"�س]��",1)>0 then
			if  stra_dp08="" then
				stra_dp08= worker_a(ki-1)
			else  
				stra_dp08= stra_dp08 & "," & worker_a(ki-1)
			end if
	end if
	if instr(1,staff_dp_a(ki-1),"����",1)>0 then
			if  stra_dp09="" then
				stra_dp09= worker_a(ki-1)
			else  
				stra_dp09= stra_dp09 & "," & worker_a(ki-1)
			end if
	end if
	if instr(1,staff_dp_a(ki-1),"�ڮa�A�~",1)>0 then
			if  stra_dp10="" then
				stra_dp10= worker_a(ki-1)
			else  
				stra_dp10= stra_dp10 & "," & worker_a(ki-1)
			end if
	end if
	 
'	Select Case staff_dp_a(ki-1)
'		Case "�`�g�z��" 
'			if  stra_dp01="" then
'				stra_dp01= worker_a(ki-1)
'			else  
'				stra_dp01= stra_dp01 & "," & worker_a(ki-1)
'			end if
'		Case "�޲z��"  
'			if  stra_dp02="" then
'				stra_dp02= worker_a(ki-1)
'			else  
'				stra_dp02= stra_dp02 & "," & worker_a(ki-1)
'			end if
'		Case "������"  
'			if  stra_dp03="" then
'				stra_dp03= worker_a(ki-1)
'			else  
'				stra_dp03= stra_dp03 & "," & worker_a(ki-1)
'			end if
'		Case "�~�ȳ�"  
'			if  stra_dp04="" then
'				stra_dp04= worker_a(ki-1)
'			else  
'				stra_dp04= stra_dp04 & "," & worker_a(ki-1)
'			end if
'		Case "�k�ȳ�"  
'			if  stra_dp05="" then
'				stra_dp05= worker_a(ki-1)
'			else  
'				stra_dp05= stra_dp05 & "," & worker_a(ki-1)
'			end if
'		Case "�]�ȳ�"  
'			if  stra_dp06="" then
'				stra_dp06= worker_a(ki-1)
'			else  
'				stra_dp06= stra_dp06 & "," & worker_a(ki-1)
'			end if
'		Case "��T��"  
'			if  stra_dp07="" then
'				stra_dp07= worker_a(ki-1)
'			else  
'				stra_dp07= stra_dp07 & "," & worker_a(ki-1)
'			end if
'		Case "�س]��"  
'			if  stra_dp08="" then
'				stra_dp08= worker_a(ki-1)
'			else  
'				stra_dp08= stra_dp08 & "," & worker_a(ki-1)
'			end if
'		Case "����"  
'			if  stra_dp09="" then
'				stra_dp09= worker_a(ki-1)
'			else  
'				stra_dp09= stra_dp09 & "," & worker_a(ki-1)
'			end if
'		Case "�ڮa�A�~"  
'			if  stra_dp10="" then
'				stra_dp10= worker_a(ki-1)
'			else  
'				stra_dp10= stra_dp10 & "," & worker_a(ki-1)
'			end if
'		Case Else     
'	End Select

	Select Case staff_gp_a(ki-1)
		Case "�~1" 
			if  stra_dpa1="" then
				stra_dpa1= worker_a(ki-1)
			else  
				stra_dpa1= stra_dpa1 & "," & worker_a(ki-1)
			end if
		Case "�~2" 
			if  stra_dpa2="" then
				stra_dpa2= worker_a(ki-1)
			else  
				stra_dpa2= stra_dpa2 & "," & worker_a(ki-1)
			end if
		Case "�~3" 
			if  stra_dpa3="" then
				stra_dpa3= worker_a(ki-1)
			else  
				stra_dpa3= stra_dpa3 & "," & worker_a(ki-1)
			end if
		Case "�~4" 
			if  stra_dpa4="" then
				stra_dpa4= worker_a(ki-1)
			else  
				stra_dpa4= stra_dpa4 & "," & worker_a(ki-1)
			end if
		Case "�~5" 
			if  stra_dpa5="" then
				stra_dpa5= worker_a(ki-1)
			else  
				stra_dpa5= stra_dpa5 & "," & worker_a(ki-1)
			end if
		Case Else     
	End Select
	
next




%>


	