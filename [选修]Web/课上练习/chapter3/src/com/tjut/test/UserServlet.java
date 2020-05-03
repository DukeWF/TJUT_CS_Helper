package com.tjut.test;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.alibaba.fastjson.JSONArray;
import com.tjut.common.WebUtil;
import com.tjut.database.DBUtil;

@WebServlet("/UserServlet")
public class UserServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request,response);
	}	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String caozuo=WebUtil.getParameter(request, "caozuo");
		switch(caozuo){
		case "query":
			handle(request,response);
			break;
		case "delete":
			delete(request,response);
			break;
		}
	}
	
	private void handle(HttpServletRequest request,HttpServletResponse response){
		ArrayList<HashMap<String, String>> list=null;
		try{	
			String uid=WebUtil.getParameter(request, "uid");
			String sql="select * from users";// where uid='"+uid+"'";
			list=DBUtil.getDataSet(sql);
			String data=JSONArray.toJSONString(list);
			
			response.setCharacterEncoding("utf-8"); 
			PrintWriter out=response.getWriter();
			out.print(data);;
			out.flush();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	private void delete(HttpServletRequest request,HttpServletResponse response){
		ArrayList<String> list=new ArrayList<String>();
		try{	
			String uid=WebUtil.getParameter(request, "uid");
			String sql="delete from users where uid='"+uid+"'";
			list.add(sql);
			boolean flag=DBUtil.executeBatch(list);
			if(flag){
				response.setCharacterEncoding("utf-8"); 
				PrintWriter out=response.getWriter();
				out.print("ok!");
			}else{
				response.setCharacterEncoding("utf-8"); 
				PrintWriter out=response.getWriter();
				out.print("false!");;
			}			
		}catch(Exception e){
			e.printStackTrace();
		}
	}

}
