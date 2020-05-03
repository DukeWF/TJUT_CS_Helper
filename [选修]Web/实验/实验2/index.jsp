<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'index.jsp' starting page</title>
	<link href="<%=basePath %>css/icon.css" rel="stylesheet" type="text/css" />
     <link href="<%=basePath %>css/easyui.css" rel="stylesheet" type="text/css" />
     <script type="text/javascript" src="<%=basePath %>js/jquery.min.js"></script>
     <script type="text/javascript" src="<%=basePath %>js/jquery.easyui.min.js"></script> 
     <script>
        $(function(){
            $(".easyui-linkbutton").click(function(){
        // 获取组件的属性和值    
        var str = $(this).text();
        var tab_href = $(this).attr("title");
            if($("#tt").tabs('exists',str)){
                $("#tt").tabs('select',str);
            }else{
                $("#tt").tabs('add',{title:str,closable:true,//href:tab_href
                content:"<iframe width='100%' frameborder='0' height='100%' src='"+ tab_href +"'></iframe>"    
                });
                }
        });
        });
     </script>
  </head>
  
  <body>
    <!-- 布局 -->
<div id="cc" class="easyui-layout" style="width:100%;height:900px;">   
    
     <!-- 顶部 -->
    <div data-options="region:'north',split:true," style="height:108px;">
        <div style="width:100%;height:100px;margin-top:0px;">
          <img alt="" src="images/head.jpg" width="100%">
       </div>       
    </div> 
    <!-- 左侧导航 -->   
    <div data-options="region:'west',title:'导航菜单',split:true" style="width:15%;">
    <!-- 导航菜单 -->
    <div id="aa" class="easyui-accordion" style="width:100%;height:99%;">   
	    <div title="基本信息/打卡" style="overflow:auto;">   
		    <a class="easyui-linkbutton" id="add_tab" href="#" style="width:100%" title="dakaMain.jsp">上下班打卡</a><br> 
		    <a class="easyui-linkbutton" href="#" style="width:100%" data-options="iconCls:'icon-search'" title="shangxiabanBiaoZhun.jsp">上下班标准</a><br>        
		</div>   
	    <div title="查询考勤信息" style="overflow:auto;">   
		    <a class="easyui-linkbutton" href="#" style="width:100%" data-options="iconCls:'icon-ok'" title="rikaoqinxinxi.jsp">日考勤信息</a><br>        
		    <a class="easyui-linkbutton" href="#" style="width:100%" data-options="iconCls:'icon-undo'" title="yuekaoqinxinxi.jsp">月考勤信息</a><br> 
		    <a class="easyui-linkbutton" href="#" style="width:100%" data-options="iconCls:'icon-man'" title="jiabanxinxi.jsp">加班信息</a><br> 
		    <a class="easyui-linkbutton" href="#" style="width:100%" data-options="iconCls:'icon-add'" title="tongjiyuekaoqin.jsp">统计月考勤</a><br>
		</div>   
	    <div title="请假申请">   
		    <a class="easyui-linkbutton" href="#" style="width:100%" data-options="iconCls:'icon-tip'" title="qingjiaxinxi.jsp">请假信息</a><br>
		    <a class="easyui-linkbutton" href="#" style="width:100%" data-options="iconCls:'icon-ok'" title="Qingjiashenqing.jsp">请假申请</a><br>       
		</div>   
    </div>  
    
    </div>  
    <!-- 中部内容显示 --> 
    <div data-options="region:'center',title:'信息展示'" style="padding:5px;background:#eee;">
    <!-- 标签页 -->
    <div id="tt" class="easyui-tabs" style="width:100%;height:100%;background:url(images/background.png)"></div>
    </div>   
</div>   
</div>
  </body>
</html>
