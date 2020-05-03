package com.tjut.common;

import java.io.UnsupportedEncodingException;

import javax.servlet.http.HttpServletRequest;

public class WebUtil {
   public static String getParameter(HttpServletRequest request,String name) throws UnsupportedEncodingException{
	   request.setCharacterEncoding("utf-8");
	   String data=request.getParameter(name);
	   return data==null?"":data;
   }
}
