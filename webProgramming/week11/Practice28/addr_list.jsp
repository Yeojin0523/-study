<!-- 20220803 컴퓨터학과 정여진 -->
<!-- 엣지 최적화 -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>addr_list.jsp</title>
<style>body{text-align:center};</style>
</head>
<body>
	<h2>주소록</h2><hr>
	<%
	int i = 0;
    ArrayList<String> addr = (ArrayList<String>)application.getAttribute("addrbook");
    if (addr != null) {
    	 out.println("<ol>");
    	for (String entry : addr){
            out.println("<li>" + entry + "</li>");
        }
    	out.println("</ol>");
    }
	%>
	<hr>
	<a href="addr_form.jsp">주소추가</a>
</body>
</html>