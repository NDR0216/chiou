
<!--<table border=1 cellspacing=0 cellpadding=0>
<col width=120><col width=120><col width=120><col width=120><col width=120><col width=120>
-->
<table border=1 cellspacing=0 cellpadding=0>
<col width=150>
<col width=180>
<col width=100>
<col width=180>
<col width=100>
<col width=180>
<tr>
	<td align="center" colspan=6><font size=3 color="red">���G��ק�u�@�����B�������B�D���B����H���B���|�H���ΰO�����椺�e</font></td>
</tr>

<tr>
	<td align="center" colspan=2 rowspan=2><font size=4 color="red"><b>�s�׳�@�u�@��</b></font></td>
	<td align="right">�u�@�s�աG</td>
	<td><input type='text' name='wk_group' value='<%=wk_group1%>' style="width:100%;" readonly onkeydown="javascript:if(window.event.keyCode==8) return false;"></td>
	<td align="right"><font color="red">�M�צW�١G</font></td>
	<td>
<!-- 	<select name="wk_pjn" style="width:100%;height:100%;font-size:10pt;background-color:'#ffffee';" onchange="pjnsel()"> -->
	<select name="wk_pjn" style="width:100%;height:100%;font-size:10pt;background-color:'#ffffee';" >
<%
		response.write "<option value='�A' >"
		'response.write "<option value='"&pjnid_a(0)&"' >"&pjn_a(0)
	for i=1 to pjn_no
	    if  wk_pjn=pjn_a(i-1) then
      		response.write "<option value='"&pjnid_a(i-1)&"�A"&pjn_a(i-1)&"' selected>"&pjn_a(i-1)
	    else
      		response.write "<option value='"&pjnid_a(i-1)&"�A"&pjn_a(i-1)&"'>"&pjn_a(i-1)
         end if
	next
%>
	</select>
	</td>	
</tr>
<tr>
<!-- 	<td align="center" colspan=2><font size=4 color="red"><b>�s�׳�@�u�@��(<%=wk_group1%>)</b></font></td>
 -->
 	<td align="right">�u�@�s���G</td>
	<td><input type='text' name='wk_id' value='<%=wk_id%>' style="width:100%;" readonly onkeydown="javascript:if(window.event.keyCode==8) return false;"></td>
	<td align="right"><font color="red"><b>�u�@�����G</b></font></td>
	<td>
	<select name="wk_class" style="width:100%;height:100%;font-size:10pt;background-color:'#ffffee'" >
<%
	for i=1 to wk_class_no
	if wk_class_a(i-1)=wk_class1 then
		response.write "<option value='"&wk_class_a(i-1)&"' selected>"&wk_class_a(i-1)
	else
		response.write "<option value='"&wk_class_a(i-1)&"'>"&wk_class_a(i-1)
	end if
	  if wk_class_a(i-1)="Z" then response.write "-���n����"
	next
%>
	</select>
	</td>
</tr>

<tr>
	<td align="right">���i�̡G</td>
	<td><input type='text' name='wk_order' value='<%=wk_order%>' style="width:100%;" readonly onkeydown="javascript:if(window.event.keyCode==8) return false;"></td>
	<td align="right">���i����G</td>
	<td><input type='text' name='undo_date1' value='<%=undo_date1%>' style="width:100%;" readonly onkeydown="javascript:if(window.event.keyCode==8) return false;"></td>
	<td align="right"><font color="red"><b>�������G</b></font></td>
	<td><input type='text' name='doing_date1' value='<%=doing_date1%>' style="width:100%;" ></td>
</tr>
<tr style="background-color:#FFFF33;">
	<td align="right">
		<font style="background-color:#ddd;text-decoration:none;cursor:hand;color:red;" onclick="addexe_none()" title="�M������H�����">[�M]</font>
	<font style="color:blue;">����H���G</font>
	</td>
	<td colspan=5>
	<input type='text' name='wk_exe' value='<%=wk_exe1%>' style="width:50%;" readonly title="����H���бĥΥk��U�Կ���J�I�I�I" onkeydown="javascript:if(window.event.keyCode==8) return false;">
		<SELECT name="exemen_w" onchange="exeadd()">
		<option value="" selected>�п�ܤH��</option>
		<option value="clear" >�M���H��</option>
			<option value="����H��" >����H��</option>
		<option value="�~�ȥ���" >�~�ȥ���</option>
		<option value="���ԥ���" >���ԥ���</option>
	<%
		for i=1 to worker_no
			response.write "<option value='" & worker_a(i-1) & "'>" & worker_a(i-1) &"</option>"
		next
	%>

		</SELECT>

		<SELECT name="exemen_dp" onchange="exeadddp()">
			<option value="" selected>�������</option>
			<option value="clear" >�M���H��</option>
			<option value="<%=stra_dp01%>" >�`�g�z��</option>
			<option value="<%=stra_dp02%>" >�޲z��</option>
			<option value="<%=stra_dp03%>" >������</option>
			<option value="<%=stra_dp04%>" >�~�ȳ�</option>
			<option value="<%=stra_dp05%>" >�k�ȳ�</option>
			<option value="<%=stra_dp06%>" >�]�ȳ�</option>
			<option value="<%=stra_dp07%>" >��T��</option>
			<option value="<%=stra_dp08%>" >�س]��</option>
<!--			<option value="<%=stra_dp09%>" >����</option>-->
			<option value="<%=stra_dp10%>" >�ڮa�A�~</option>
			<option value="<%=stra_dpa1%>" >�~�@</option>
			<option value="<%=stra_dpa2%>" >�~�G</option>
			<option value="<%=stra_dpa3%>" >�~Three</option>
			<option value="<%=stra_dpa4%>" >YES</option>
			<option value="<%=stra_dpa5%>" >�_�w�~�K</option>
		</SELECT>	
				(�п�J����ѻP�H��)	
	</td>
</tr>

<tr style="background-color:#FFBFFF;">
	<td align="right">
		<font style="background-color:#ddd;text-decoration:none;cursor:hand;color:red;" onclick="addatt_none()" title="�M���X�u�H�����">[�M]</font>
	<font style="color:blue;">�X�u�H���G</font>
	</td>
	<td colspan=5>
	<input type='text' name='wk_att' value='<%=wk_att%>' style="width:50%;" >
		<SELECT name="attmen_w" onchange="attadd()">
		<option value="" selected>�п�ܤH��</option>
		<option value="clear" >�M���H��</option>
			<option value="����H��" >����H��</option>
		<option value="�~�ȥ���" >�~�ȥ���</option>
		<option value="���ԥ���" >���ԥ���</option>
	<%
		for i=1 to worker_no
			response.write "<option value='" & worker_a(i-1) & "'>" & worker_a(i-1) &"</option>"
		next
	%>

		</SELECT>

		<SELECT name="attmen_dp" onchange="attadddp()">
			<option value="" selected>�������</option>
			<option value="clear" >�M���H��</option>
			<option value="<%=stra_dp01%>" >�`�g�z��</option>
			<option value="<%=stra_dp02%>" >�޲z��</option>
			<option value="<%=stra_dp03%>" >������</option>
			<option value="<%=stra_dp04%>" >�~�ȳ�</option>
			<option value="<%=stra_dp05%>" >�k�ȳ�</option>
			<option value="<%=stra_dp06%>" >�]�ȳ�</option>
			<option value="<%=stra_dp07%>" >��T��</option>
			<option value="<%=stra_dp08%>" >�س]��</option>
<!--			<option value="<%=stra_dp09%>" >����</option>-->
			<option value="<%=stra_dp10%>" >�ڮa�A�~</option>
			<option value="<%=stra_dpa1%>" >�~�@</option>
			<option value="<%=stra_dpa2%>" >�~�G</option>
			<option value="<%=stra_dpa3%>" >�~Three</option>
			<option value="<%=stra_dpa4%>" >YES</option>
			<option value="<%=stra_dpa5%>" >�_�w�~�K</option>
		</SELECT>	
				(�п�J�����X�u�H��)	
	</td>
</tr>
<!--
<tr style="background-color:#FFFF33;">
	<td align="right">
	<font color="blue">����H���G</font>
	</td>
	<td colspan=5>
	<input type='text' name='wk_exe' value='<%=wk_exe1%>' style="width:50%;" readonly title="����H���бĥΥk��U�Կ���J�I�I�I" onkeydown="javascript:if(window.event.keyCode==8) return false;">
		<SELECT name="exemen_w" onchange="exeadd()">
		<option value="" selected>�п�ܤH��</option>
		<option value="clear" >�M���H��</option>
		<option value="����H��" >����H��</option>
		<option value="�~�ȥ���" >�~�ȥ���</option>
		<option value="���ԥ���" >���ԥ���</option>
	<%
		for i=1 to worker_no
			response.write "<option value='" & worker_a(i-1) & "'>" & worker_a(i-1) &"</option>"
		next
	%>

		</SELECT>
		(�п�J����ѻP�H��)
	</td>
</tr>
-->

<tr>
	<td align="right">
	<font color="red"><b>���|�H���G</b></font>
	</td>
	<td colspan=5>
	<input type='text' name='wk_doer' value='<%=wk_doer%>' style="width:100%;" >
	</td>
</tr>
<tr>
	<td colspan=6 align="center">


		<table border=0 cellspacing=0 cellpadding=0 style="" >
<%
      ckn001=0	
	for i=1 to worker_no
      	if left(staff_dp_a(i-1),1)="�k" and ckn001=0 then
      	  response.write  "<tr style='text-align:center;'>"
      	  ckn001=1
      	end if
	'if i=1 or i=17 then  response.write  "<tr style='text-align:center;'>"
	response.write "<td>"	
%>
	<input type="button"  style="width:35px;"  name="worker_s<%=i%>" value="<%=worker_a(i-1)%>" onclick="worker_s<%=i%>_click()">
<%
   'response.write "</td>"
   'if i=1 or i=13 then  response.write  "</tr>"
	next
%>	
	<td><input type="button" style="width:35px;"  name="all_unsel" value="�M��" onclick="all_unsel_click()">
		</table>
	</td>
</tr>
<tr>
	<td align="right">
	�����H���G
	</td>
	<td colspan=5>
	<input type='text' name='wk_checker' value='<%=wk_checker%>' style="width:100%;" >
	</td>
</tr>
<tr>
	<td align="right">
	�������H���G
	</td>
	<td colspan=5>
	<input type='text' name='wk_undoer' value='<%=wk_undoer%>' style="width:100%;" >
	</td>
</tr>
<tr>
	<td align="right">
	<font color="red"><b>�D���G</b></font>
	</td>
	<td colspan=5>
	<input type='text' name='wk_item' value='<%=wk_item%>' style="width:100%;" >
	</td>
</tr>
<tr>
	<td align="right" valign="top" bgcolor="yellow">
	<font color="red"><b>���椺�e�G</b></font><br>
	�q�����e�ק�G<br>
	<input type='radio' name="redo" value="�O" >�O
	<input type='radio' name="redo" value="�_" checked>�_
	</td>
	<td colspan=5 bgcolor="yellow">
	<TEXTAREA name="wk_content" rows="10" style="width:100%;" ><%=wk_content%>&#013;<%=worker%>(<%=now()%>)�G&#013;</TEXTAREA>
	</td>
</tr>
<tr>
	<td align="right">
	<font color="red">�[�K��r�G</font>
	</td>
	<td colspan=5>
	<input type='text' name='str_pwd' value='<%=pwk_password%>' style="width:100px;" maxlength=10>
	</td>
</tr>
</table>
<script language=vbscript>
sub attadd()'�X�u�H��
  if document.form1.attmen_w.value="clear" then
   document.form1.wk_att.value=""
  else
	if document.form1.wk_att.value="" then
		document.form1.wk_att.value=document.form1.attmen_w.value
	else
         if instr(1,document.form1.wk_att.value,document.form1.attmen_w.value,1)>0 then
            document.form1.wk_att.value=replace(document.form1.wk_att.value,document.form1.attmen_w.value,"")
            document.form1.wk_att.value=replace(document.form1.wk_att.value,",,",",")
            if left(document.form1.wk_att.value,1)="," then document.form1.wk_att.value=right(document.form1.wk_att.value,len(document.form1.wk_att.value)-1)
            if right(document.form1.wk_att.value,1)="," then document.form1.wk_att.value=left(document.form1.wk_att.value,len(document.form1.wk_att.value)-1)
         else
		document.form1.wk_att.value=document.form1.wk_att.value & "," & document.form1.attmen_w.value
         end if
	end if
  end if
	document.form1.attmen_w.value=""
end sub	
sub exeadd()
  if document.form1.exemen_w.value="clear" then
   document.form1.wk_exe.value=""
  else
	if document.form1.wk_exe.value="" then
		document.form1.wk_exe.value=document.form1.exemen_w.value
	else
         if instr(1,document.form1.wk_exe.value,document.form1.exemen_w.value,1)>0 then
            document.form1.wk_exe.value=replace(document.form1.wk_exe.value,document.form1.exemen_w.value,"")
            document.form1.wk_exe.value=replace(document.form1.wk_exe.value,",,",",")
            if left(document.form1.wk_exe.value,1)="," then document.form1.wk_exe.value=right(document.form1.wk_exe.value,len(document.form1.wk_exe.value)-1)
            if right(document.form1.wk_exe.value,1)="," then document.form1.wk_exe.value=left(document.form1.wk_exe.value,len(document.form1.wk_exe.value)-1)
         else
		document.form1.wk_exe.value=document.form1.wk_exe.value & "," & document.form1.exemen_w.value
         end if
	end if
  end if
	document.form1.exemen_w.value=""
end sub
sub attadddp()    '==20170606�s�W===�����ﶵ===�X�u�H��=====
  if document.form1.attmen_dp.value="clear" then
   document.form1.wk_att.value=""
  else
	if document.form1.wk_att.value="" then
		document.form1.wk_att.value=document.form1.attmen_dp.value
	else
         if instr(1,document.form1.wk_att.value,document.form1.attmen_dp.value,1)>0 then
            document.form1.wk_att.value=replace(document.form1.wk_att.value,document.form1.attmen_dp.value,"")
            document.form1.wk_att.value=replace(document.form1.wk_att.value,",,",",")
            if left(document.form1.wk_att.value,1)="," then document.form1.wk_att.value=right(document.form1.wk_att.value,len(document.form1.wk_att.value)-1)
            if right(document.form1.wk_att.value,1)="," then document.form1.wk_att.value=left(document.form1.wk_att.value,len(document.form1.wk_att.value)-1)
         else
		document.form1.wk_att.value=document.form1.wk_att.value & "," & document.form1.attmen_dp.value
         end if
	end if
  end if
	document.form1.attmen_dp.value=""
end sub

sub exeadddp()    '==20151209�s�W===�����ﶵ===����H��=====
  if document.form1.exemen_dp.value="clear" then
   document.form1.wk_exe.value=""
  else
	if document.form1.wk_exe.value="" then
		document.form1.wk_exe.value=document.form1.exemen_dp.value
	else
         if instr(1,document.form1.wk_exe.value,document.form1.exemen_dp.value,1)>0 then
            document.form1.wk_exe.value=replace(document.form1.wk_exe.value,document.form1.exemen_dp.value,"")
            document.form1.wk_exe.value=replace(document.form1.wk_exe.value,",,",",")
            if left(document.form1.wk_exe.value,1)="," then document.form1.wk_exe.value=right(document.form1.wk_exe.value,len(document.form1.wk_exe.value)-1)
            if right(document.form1.wk_exe.value,1)="," then document.form1.wk_exe.value=left(document.form1.wk_exe.value,len(document.form1.wk_exe.value)-1)
         else
		document.form1.wk_exe.value=document.form1.wk_exe.value & "," & document.form1.exemen_dp.value
         end if
	end if
  end if
	document.form1.exemen_dp.value=""
end sub
sub addexe_none()
    document.form1.wk_exe.value=str_old
end sub

sub addatt_none()
    document.form1.wk_att.value=str_old
end sub
</script>