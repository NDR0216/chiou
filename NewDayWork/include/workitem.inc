
<table border="0" cellspacing="0" cellpadding="0">
<col width=120><col width=120><col width=120><col width=120><col width=120>
<tr><td align="center" valign="middle">
	<!-- �H���ﶵ -->
	<font size=3>�H���ﶵ�G<br>
		<SELECT name="men_w" onchange="menadd">
		<option selected>�п�ܤH��</option>
	<%
		for i=1 to writer_no
			response.write "<option value='"&writer_a(i-1)&"'>"&writer_a(i-1)
		next
	%>
		</font></SELECT>
	</td>
	<td align="center" valign="middle">
	<!-- ����ﶵ -->
	<font size=3>����ﶵ�G<br>
		<SELECT name="date_w" onchange="dateadd">
		<option selected>�п�ܤ��</option>
	<%
	for i=1 to 60
		Response.Write("<OPTION value=" & wk_date(i-1) & ">" & wk_date(i-1)&"</OPTION>")
	next
	%>
		</font></SELECT>
	</td>
	<td align="center" valign="middle">
	<!-- �ɶ��ﶵ -->
	<font size=3>�ɶ��ﶵ�G<br>
		<SELECT name="time_w" onchange="timeadd">
		<option selected>�п�ܮɶ�</option>
	<%
	for i=1 to 19
		Response.Write("<OPTION value=" & wk_time(i-1) & ">" & wk_time(i-1)&"</OPTION>")
	next
	%>
		</font></SELECT>
	</td>
	<td align="center" valign="middle">
	<!-- �a�I�ﶵ -->
	<font size=3>�a�I�ﶵ�G<br>
		<SELECT name="place_w" onchange="placeadd">
		<option selected>�п�ܦa�I</option>
	<%
		for i=1 to place_no
			response.write "<option value='"&place_a(i-1)&"'>"&place_a(i-1)
		next
	%>
		</font></SELECT>
	</td>
	<td align="center" valign="middle">
	<!-- �ƥ�ﶵ -->
	<font size=3>�ƥ�ﶵ�G<br>
		<SELECT name="thing_w" onchange="thingadd">
		<option selected>�п�ܨƥ�</option>
	<%
		for i=1 to thing_no
			response.write "<option value='"&thing_a(i-1)&"'>"&thing_a(i-1)
		next
	%>
		</font></SELECT>
	</td>

</tr>
</table>