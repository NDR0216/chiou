<%@ Language=VBScript CODEPAGE=950 %>
<%
ndate=date()
'�H���s�հ}�C staff_a()
'../daywork/database/daywork.mdb  tb_name_acr="worker_data"
dim staff_a()
dim staff_gp_a()
dim staff_id_a()
' �s��Access��Ʈw../daywork/database/daywork.mdb
DBpath_acr=Server.MapPath("./database/crew.mdb")
strCon_acr="Driver={Microsoft Access Driver (*.mdb)};DBQ="&DBpath_acr
'�إ߸�Ʈw�s������
set conDB_acr= Server.CreateObject("ADODB.Connection")
'�s����Ʈw	
conDB_acr.Open strCon_acr
'�}�Ҹ�ƪ��W��
tb_name_acr="crew"
'�إ߸�Ʈw�s������	
set rstObj_acr=Server.CreateObject("ADODB.Recordset")
strSQL_acr="Select * from " & tb_name_acr &" where (wk_gp like '%������%' or wk_gp like '%��T��%' or wk_gp like '%�޲z��%' ) and not((hide=true) and (st_qdate < #"& date() &"# )) order by wk_sgp asc, wk_gp_sq, wkr_id asc"
rstObj_acr.open strSQL_acr,conDB_acr,1,3
'�p�����`��	
staff_no=rstObj_acr.recordcount
'���]�}�C�ƥ�
redim staff_a(Cint(staff_no))
redim staff_gp_a(Cint(staff_no))
redim staff_id_a(Cint(staff_no))
rstObj_acr.MoveFirst
for icr=1 to staff_no
	staff_id_a(icr-1)=rstObj_acr.fields("wkr_id") 'id
	staff_a(icr-1)=rstObj_acr.fields("e_name") '�ʺ�
	staff_gp_a(icr-1)=rstObj_acr.fields("wk_sgp") '�s��
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
<%
'�w��user_id Ū���ϥΪ̱K�X
function read_userpwd(user_id)

'01_personnel.mdb  tb_name_acr="staff_basic"

' �s��Access��Ʈw01_personnel.mdb
DBpath_acr=Server.MapPath("./database/crew.mdb")
strCon_acr="Driver={Microsoft Access Driver (*.mdb)};DBQ="&DBpath_acr
'�إ߸�Ʈw�s������
set conDB_acr= Server.CreateObject("ADODB.Connection")
'�s����Ʈw	
conDB_acr.Open strCon_acr
'�}�Ҹ�ƪ��W��
tb_name_acr="crew"
'�إ߸�Ʈw�s������	
set rstObj_acr=Server.CreateObject("ADODB.Recordset")
strSQL_acr="Select * from " & tb_name_acr & " where wkr_id =" & user_id
rstObj_acr.open strSQL_acr,conDB_acr,1,3

	ps_pwd=rstObj_acr.fields("st_pwd")

'������ƶ�
rstObj_acr.Close
'���]����ܼ� 
set rstObj_acr=Nothing
'������Ʈw
conDB_acr.Close
'���]�����ܼ�
set conDB_acr=Nothing

   read_userpwd = ps_pwd
end function
%>
<%
   'Ū����Ʊb���B�K�X
   p_userid=request("user_id")
   p_pwd=request("pwd")

if p_userid="" or isnull(p_userid) then
   session("num_error")=0

else
   '�P�_�ϥΪ̤��K�X�O�_���T
   'Ū���ϥΪ̱K�X
      if isnumeric(p_userid) then p_userid=cint(p_userid)
      g_pwd=read_userpwd(p_userid)
      if p_pwd=g_pwd then
         '�K�X���T�Nid�g�Jsession���æ^��e�@�e��
         session("g_userid")=p_userid
'�Nfrm_top��������s

'�Nfrm_main��������}������ϥΪ̵n�J�e���e��
         str_url="./00_03_manager_page.asp?p_uid="& p_userid
         response.redirect(str_url)
      else
         p_num_error=session("num_error")
         session("num_error")=p_num_error+1
         str_msg="�K�X���~�A�Э��s��J�I�I"
      end if
end if


%>

<html>
<head>
<title>�޲z���޲z�t�Ρi�n�J�e���j</title>
<meta http-equiv="Content-Type" content="text/html; charset=big5">
<link rel="icon" href="../daywork/img/khouse.ico" type="image/ico" />
<style type="text/css"><!--
body{font-family:'�s�ө���';background-color :'#FFFEEE'}
input{
	font-family:'�s�ө���';
	font-size:12pt;
	}
select{font-family:'�s�ө���';font-size:10pt;cursor:hand;}
.itxt{
	font-family:'�s�ө���';
	font-size:12pt;
	width:100%;
	height:100%;
	}
input.imenu { 
	/*font-size:15px;				/*�r��j�p*/
	/*font-weight:bold;
	cursor:hand;				/*��ЧΦ�*/ 
	background-color:'<%=botton_color%>'; 		
	margin:0 0 0 0;		/*��t�W�U���k*/
	width:100px;
	/*height:100%;*/
	color:#000000;
	letter-spacing:2px;
	cursor:hand;
     }
td{
	margin:0 0 0 0;		/*��t�W�U���k*/
	border-color:'#808080'; /*����~���C��*/ 
	border-style:solid;		/*����~�ؽu��*/
	border-width:1px;		/*����~�ثp��*/
	vertical-align:middle;	/*�r�髫������覡*/
	/*font-size:15px;*/ 
	}
table{	
	margin:0 0 0 0;		/*��t�W�U���k*/
	border-collapse:collapse; 	/*��اΦ����X*/
	}
input.itext { 
	font-size:3.5mm;				/*�r��j�p*/
	/*cursor:hand;				/*��ЧΦ�*/ 
	width:100%;
	height:5mm;
	background-color:'#ffeedd'; 		/*�~���C��*/
	margin:0 0 0 0;		/*��t�W�U���k*/
	color:black;
	text-align:right;
     }

--></style>
</head>
<body>
<center>
<form name="form_login" method=post action="00_03_manager.asp">

<font style="font-family:'�з���';font-size:30px;font-weight:bold;letter-spacing:15px;">��j�޲z���޲z�t��</font>
<hr width=300>
<font style="font-size:20px;font-weight:bold;letter-spacing:15px;">�i�n�J�e���j</font>
<br>
<hr color=red> 
<table border=0 cellspacing=0 cellpadding=2 style="width:600px" >
<col style="width:100px;font-size:4mm;" align=center>
<col style="width:500px;font-size:4mm;" align=center>
<tr>
<td colspan=2 style="text-align:left;padding-left:2px;">
   <table border=0 cellspacing=0 cellpadding=0>
      <tr>
<%
   for i_01=1 to staff_no
%>
  <td style="width:100px;border-width:0px;font-weight:bold;"><input type=radio name="user_id" value="<%=staff_id_a(i_01-1)%>" > <%=staff_a(i_01-1)%>
<%
      schk=i_01 mod 6
      if  schk=0 then response.write "<tr>"
   next
%>
   </table>
</td>
</tr>
<tr>
<td>�K�X�G</td>
<td><input type="password" style="text-align:left;width:100%;" name="pwd" value="" ></td>
</tr>
<tr>
<td colspan=2>
	<input type="submit" name="submit01" value="�T�w" >
	<input type="reset" name="reset01" value="���]" >
</td>
</tr>
</table>
<hr color=red>
<font style="font-size:20px;font-weight:bold;letter-spacing:15px;">�K�X���������K�X�C</font>
<hr color=red>
<font style="font-size:20px;font-weight:bold;letter-spacing:15px;"><%=str_msg%></font>
<hr color=red width=660>

</form>
<script language="vbscript" >
<!-- 

--> 
</script>	
</body>
</html>
