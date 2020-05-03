package com.tjut.database;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.HashMap;

public class DBUtil {
   private static String url="jdbc:sqlserver://127.0.0.1:1433;databasename=demo";
   private static String user="sa";
   private static String pwd="ywj020318";
   
   private static Connection conn=null;
   private static Statement st=null;
   private static ResultSet rs=null;
   //连接
   private static Connection getConn(){
	   try{
		   Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
		   conn=DriverManager.getConnection(url,user,pwd);
		   
	   }catch(Exception ex){
		   ex.printStackTrace();
	   }
	   return conn;
   }
   //ArrayList<HashMap<String,String>>
   //查询，返回：ArrayList
   public static ArrayList<HashMap<String,String>> getDataSet(String sql){
	   HashMap<String,String> hash=new HashMap<String,String>();
	   ArrayList<HashMap<String,String>> list=new ArrayList<HashMap<String,String>>();
	   ResultSetMetaData rsma=null;
	   int columncount=0;
	   
	   try{
		   conn=DBUtil.getConn();
		   st=conn.createStatement();
		   rs=st.executeQuery(sql);
		   rsma=rs.getMetaData();
		   while(rs.next()){
			   columncount=rsma.getColumnCount();
			   for(int i=1;i<=columncount;i++){
				   hash.put(rsma.getColumnName(i), rs.getString(i));
			   }
			   list.add(hash);
		   }
		   
	   }catch(Exception ex){
		   ex.printStackTrace();
	   }finally{
		   finallyHandle(conn,st,rs);
	   }
	   return list;
   }
   //insertupdatedelete
   public static boolean executeBatch(ArrayList<String> list){
	   boolean flag=true;
	   try{
		   conn=getConn();
		   conn.setAutoCommit(false);
		   st=conn.createStatement();
		   for(int i=0;i<list.size();i++){
			   st.addBatch(list.get(i));
		   }
		   st.executeBatch();
		   conn.commit();
		   conn.setAutoCommit(true);
	   }catch(Exception ex){
		   	try {
			   conn.rollback();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		   	flag=false;
		    ex.printStackTrace();
	   }finally{
		   finallyHandle(conn,st,rs);
	   }
	   return flag;
   }
   
   private static void finallyHandle(Connection conn,Statement st,ResultSet rs){
	   try{
		   if(rs!=null){
			   rs.close();
			   rs=null;
		   }
		   if(st!=null){
			   st.close();
			   st=null;
		   }
		   if(conn!=null){
			   conn.close();
			   conn=null;
		   }
		   
	   }catch(Exception ex){
		   ex.printStackTrace();
	   }
   }
}










