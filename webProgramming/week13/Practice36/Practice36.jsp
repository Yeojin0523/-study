<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="jspbook.pr36.LectureBean" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.List" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice36</title>
</head>
<body>
	
	<jsp:useBean id="lb" class="jspbook.pr36.LectureBean" scope="page"/>
	<jsp:useBean id="manager" class="jspbook.pr36.LectureManager" scope="application"/>
	<form action="Practice36.jsp">
	<jsp:setProperty name="lb" property="*"/>
	<jsp:setProperty name="manager" property="*"/>
	
    과목타입 : <select name="lectureType">
        <% 
        String[] type_typeNames = LectureBean.typeNames;
        for (int i = 0; i < type_typeNames.length; i++) {
            out.println("<option value='" + i + "'>" + type_typeNames[i] + "</option>");
        }
        %>
    </select>

    과목이름 : <select name="titleNames">
        <% 
        String[] type_titleNames = LectureBean.titleNames;
        for (int i = 0; i < type_titleNames.length; i++) {
            out.println("<option value='" + i + "'>" + type_titleNames[i] + "</option>");
        }
        %>
    </select>

    요일 : <select name="dayNames">
        <% 
        String[] type_dayNames = LectureBean.dayNames;
        for (int i = 0; i < type_dayNames.length; i++) {
            out.println("<option value='" + i + "'>" + type_dayNames[i] + "</option>");
        }
        %>
    </select>

    시간 : <select name="time">
        <% 
        for(int i = 1; i <= 6; i++) {
            out.println("<option value='" + i + "'>" + i + "</option>");
        }
        %>
    </select>

    연강 : <select name="consecutive">
        <% 
        for(int i = 1; i <= 6; i++) {
            out.println("<option value='" + i + "'>" + i + "</option>");
        }
        %>
    </select>
    <input type="submit" value="등록">
	</form>
	<hr>

	<% 
	
    if (request.getParameter("lectureType") != null) { 
        int type = Integer.parseInt(request.getParameter("lectureType"));
        int title = Integer.parseInt(request.getParameter("titleNames"));
        int day = Integer.parseInt(request.getParameter("dayNames"));
        int time = Integer.parseInt(request.getParameter("time"));
        int consecutive = Integer.parseInt(request.getParameter("consecutive"));
        
        LectureBean newLecture = new LectureBean();
        newLecture.setType(type);
        newLecture.setTitle(title);
        newLecture.setDay(day);
        newLecture.setTime(time);
        newLecture.setConsecutive(consecutive);
        
        manager.add(newLecture);
    }
    
    List<LectureBean> lectureList = manager.getLectureList();
    
    if (lectureList != null) {
        for(LectureBean lectureEntry : lectureList) { 
%>
        <p><%= lectureEntry.toString() %></p>
<%
        }
    }
%>

</body>
</html>

