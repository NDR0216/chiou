<script language=vbscript>
<%
for i=1 TO worker_no
%>
sub worker_s<%=i%>_click
	if document.form1.all_worker.value="" then
		document.form1.all_worker.value=Trim(document.form1.worker_s<%=i%>.value)
	else
		document.form1.all_worker.value=document.form1.all_worker.value &","& Trim(document.form1.worker_s<%=i%>.value)
	end if
end sub
<%
next
%>
sub all_sel_click
	document.form1.all_worker.value=""
	<%
	for i=1 TO worker_no
	%>	
		worker_s<%=i%>_click
	<%
	next
	%>	
end sub
sub all_unsel_click
	document.form1.all_worker.value=document.form1.worker1.value
end sub
</script>
<script language=vbscript>
sub menadd
	if document.form1.wk_item.value="" then
		document.form1.wk_item.value=document.form1.men_w.value
	else	
		document.form1.wk_item.value=document.form1.wk_item.value+" "+document.form1.men_w.value
	end if
end sub
sub dateadd
	if document.form1.wk_item.value="" then
		document.form1.wk_item.value=document.form1.date_w.value
	else	
		document.form1.wk_item.value=document.form1.wk_item.value+" "+document.form1.date_w.value
	end if
	document.form1.doing_date1.value=document.form1.date_w.value
end sub
sub timeadd
	if document.form1.wk_item.value="" then
		document.form1.wk_item.value=document.form1.time_w.value
	else	
		document.form1.wk_item.value=document.form1.wk_item.value+" "+document.form1.time_w.value
	end if
end sub
sub placeadd
	if document.form1.wk_item.value="" then
		document.form1.wk_item.value=document.form1.place_w.value
	else	
		document.form1.wk_item.value=document.form1.wk_item.value+" "+document.form1.place_w.value
	end if
end sub
sub thingadd
	if document.form1.wk_item.value="" then
		document.form1.wk_item.value=document.form1.thing_w.value
	else	
		document.form1.wk_item.value=document.form1.wk_item.value+" "+document.form1.thing_w.value
	end if
end sub
sub item_chk
	if document.form1.wk_item.value="" or document.form1.all_worker.value="" or document.form1.wk_class.value="" then
		ok=msgbox("�п�J�u�@�����B�D���Ϊ��|�H���I�I",0,"���~ĵ�i")
	else
	end if
end sub
sub press_chk
	if document.form1.wk_item.value="" or document.form1.all_worker.value="" or document.form1.wk_class.value="" then
		ok=msgbox("�п�J�u�@�����B�D���Ϊ��|�H���I�I",0,"���~ĵ�i")
	else
	end if
end sub
</script>
<font size=4 color="red"><b><%=worker%>�u�@���i��</b></font>
<table border=1 cellspacing=0 cellpadding=0>
<col width=100>
<col width=130>
<col width=100>
<col width=130>
<col width=100>
<col width=130>
<tr>
	<td align="right">���i�̡G</td>
	<td><input type='text' name='wk_order' value='<%=wk_order%>' style="width:100%;" readonly></td>
	<td align="right">���i����G</td>
	<td><input type='text' name='undo_date1' value='<%=undo_date1%>' style="width:100%;" readonly></td>
	<td align="right"><font color="red">�u�@�����G</font></td>
	<td>
	<select name="wk_class" style="width:100%;height:100%;font-size:10pt;background-color:'#ffffee'" onchange="item_chk">
<%
	for i=1 to wk_class_no
		response.write "<option value='"&wk_class_a(i-1)&"'>"&wk_class_a(i-1)
	next
%>
	</select>
	</td>
</tr>
<tr>
	<td align="right">
	<font color="red">�D���G</font>
	</td>
	<td colspan=3>
	<input type='text' name='wk_item' value='' style="width:100%;" onchange="item_chk">
	</td>
	<td align="right"><font color="red">�������G</font></td>
	<td><input type='text' name='doing_date1' value='' style="width:100%;"></td>

</tr>
<tr>
	<td colspan=6 align="center">
		<!-- #Include file = "workitem.inc" -->
	</td>
</tr>
<tr>
	<td align="right">
	<font color="red">���椺�e�G</font>
	</td>
	<td colspan=5>
	<TEXTAREA name="wk_content" rows="5" style="width:100%;" ><%=wk_content%></TEXTAREA>
	</td>
</tr>
<tr>
	<td align="right">
	<font color="red">���|�H���G</font>
	</td>
	<td colspan=5>
	<input type='text' name='all_worker' value='<%=worker%>' size='85' onchange="item_chk">
	</td>
</tr>
<tr>
	<td colspan=6 align="center">
<%	
	for i=1 to worker_no
%>
	<input type="button"  name="worker_s<%=i%>" value="<%=worker_a(i-1)%>" onclick="worker_s<%=i%>_click">
<%
	next
%>	
	<input type="button" name="all_sel" value="�����H��" onclick="all_sel_click">
	<input type="button" name="all_unsel" value="�M���H��" onclick="all_unsel_click">
	</td>
</tr>
<tr>
	<td colspan=6 align="center">
	<input type="submit" name="press" value="�T�w���i" onmouseover="press_chk">
	<input type="reset" name="cancel" value="�M�����" >
	</td>
<tr>
</table>