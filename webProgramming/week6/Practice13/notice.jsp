<!-- 20220803 컴퓨터학과 정여진 -->
<!-- 엣지 최적화 -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import = "java.util.Date"%>
<%@ page errorPage="error.jsp" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice13_notice</title>
<style>
            table{
                width:100%;
            }
            div{
                text-align: center;
            }
            .image_flower{
                margin-top:20%;
                width:25%;
            }
            .text_2{
                margin-top:30px;
                margin-bottom:10%;
            }
            .table_in{
                width:60%;
                margin-left:20%;
            }
            .border_1{
                background-color: #FFDAB9;
            }
            .border_2{
                background-color: #FFEFD5;
            }
        </style>
</head>
  <body>
         <table>
            <tr>
                <td><input type="image" src="image/eclass_title.jpg" class="image_title" width="100%"></td>
            </tr>
            <tr>
                <table class="table_in">
                    <tr class="border_1">
                        <td>
                            <div class="text_1">
                                <h3>오류가 발생했습니다.</h3>
                            </div>
                        </td>
                    </tr>
                    <tr class="border_2">
                        <td>
                            <div>
                                <input type="image" src="image/flower.gif" class="image_flower">
                            </div>
                            <div class="text_2">
                                <p>오류 발생시간:</p>
  								<%=new java.util.Date()%>
  								<p>최대한 빨리 조치하겠습니다.</p>
                            </div>
                        </td>
                    </tr>
                </table>
            </tr>
        </table>
    </body>
</html>