<%
function  week_cstr(dtDate)
	select case cint(Weekday(dtDate))
            case 1
		strwk="��"
	case 2
		strwk="�@"
	case 3
		strwk="�G"
	case 4
		strwk="�T"
	case 5
		strwk="�|"
	case 6
		strwk="��"
	case 7
		strwk="��"
	case else
	end select
    week_cstr=strwk
end function			
%>			