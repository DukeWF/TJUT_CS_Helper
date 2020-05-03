package cffxq;

import java.awt.BorderLayout;
import java.awt.Desktop;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.filechooser.FileFilter;
import javax.swing.filechooser.FileNameExtensionFilter;

import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.AbstractAction;
import java.awt.event.ActionEvent;

import javax.swing.Action;
import javax.swing.BoxLayout;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

public class CfenxiGUI extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private final Action actionsearch = new SwingActionSearch();
	private final JLabel lblNewLabel = new JLabel();
	private final Action action = new SwingAction();
	private final Action action_1 = new SwingAction_1();
//	private final Action action_2 = new SwingAction_2();
//	private final Action action_3 = new SwingAction_3();
//	private final Action action_4 = new SwingAction_4();
//	private final Action action_5 = new SwingAction_5();
//	private final Action action_6 = new SwingAction_6();
//	private final Action action_7 = new SwingAction_7();
//	private final Action action_8 = new SwingAction_8();
//	private final Action action_9 = new SwingAction_9();
	private final Action action_10 = new SwingAction_10();
	private static String str;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CfenxiGUI frame = new CfenxiGUI();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public CfenxiGUI() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("C语言词法分析器");
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		JPanel panel = new JPanel();
		contentPane.add(panel, BorderLayout.NORTH);
		
		JLabel label = new JLabel("\u9009\u62E9\u6587\u4EF6 ");
		panel.add(label);
		
		panel.add(lblNewLabel);
		lblNewLabel.setVisible(false);
		
		JButton button = new JButton("\u6D4F\u89C8");
		button.setAction(actionsearch);
		panel.add(button);
		
		JPanel panel_1 = new JPanel();
		panel_1.setLayout(new BoxLayout(panel_1, BoxLayout.Y_AXIS));
		contentPane.add(panel_1, BorderLayout.WEST);
		
		JPanel panel_2 = new JPanel();
		contentPane.add(panel_2, BorderLayout.EAST);
		panel_2.setLayout(new BoxLayout(panel_2,BoxLayout.Y_AXIS));
		
		JPanel panel_3 = new JPanel();
		contentPane.add(panel_3, BorderLayout.CENTER);
		
		JPanel panel_4 = new JPanel();
		panel_3.add(panel_4);
		
		JButton btnNewButton = new JButton("\u5E03\u5C14\u578B\u5E38\u91CF");
		btnNewButton.setAction(action);
		panel_4.add(btnNewButton);
		panel_4.setLayout(new BoxLayout(panel_4, BoxLayout.Y_AXIS));
		
		JButton button_2 = new JButton("\u6D6E\u70B9\u578B\u5E38\u91CF");
		button_2.setAction(action_1);
		panel_4.add(button_2);
		
		JButton btnNewButton_2 = new JButton("\u8F93\u51FA\u7ED3\u679C");
		panel_4.add(btnNewButton_2);
		btnNewButton_2.setAction(action_10);
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
			}
		});
	}

	public static String getStr() {
		return str;
	}

	public static void setStr(String str) {
		CfenxiGUI.str = str;
	}

	private class SwingActionSearch extends AbstractAction {
		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		public SwingActionSearch() {
			putValue(NAME, "浏览");
			putValue(SHORT_DESCRIPTION, "Some short description");
		}
		public void actionPerformed(ActionEvent e) {
			FileFilter filter = new FileNameExtensionFilter("C file","c");
			JFileChooser fDialog = new JFileChooser();
			fDialog.addChoosableFileFilter(filter);
			fDialog.removeChoosableFileFilter(fDialog.getFileFilter());
			fDialog.setDialogTitle("请选择C语言文件");
			//弹出选择框
			int returnVal = fDialog.showOpenDialog(null);
			// 如果是选择了文件
			if(JFileChooser.APPROVE_OPTION == returnVal){
				lblNewLabel.setVisible(true);
				lblNewLabel.setText(fDialog.getSelectedFile().getPath());
				setStr(fDialog.getSelectedFile().getName());
				try {
					new cfenxi(fDialog.getSelectedFile().getPath());
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		}
	}
	private class SwingAction extends AbstractAction {
		 /**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		private  Desktop desktop;  
		public SwingAction() {
			putValue(NAME, "符号表");
			putValue(SHORT_DESCRIPTION, "Some short description");
		}
		public void actionPerformed(ActionEvent e) {
			 if(lblNewLabel.getText()!=""){
				  if (Desktop.isDesktopSupported()) {  
		                desktop = Desktop.getDesktop();  
		                try {  
		                    desktop.open(new File(CfenxiGUI.getStr()+"Fuhao.txt"));  
		                } catch (Exception ex) {  
		                    // TODO: handle exception  
		                    ex.printStackTrace();  
		                }  
		            }  
			}
			 else
				 JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE); 
		}
	}
	private class SwingAction_1 extends AbstractAction {
		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		private Desktop desktop;
		public SwingAction_1() {
			putValue(NAME, "常量表");
			putValue(SHORT_DESCRIPTION, "Some short description");
		}
		public void actionPerformed(ActionEvent e) {
			 if(lblNewLabel.getText()!=""){
				  if (Desktop.isDesktopSupported()) {  
		                desktop = Desktop.getDesktop();  
		                try {  
		                    desktop.open(new File(CfenxiGUI.getStr()+"Changliang.txt"));  
		                } catch (Exception ex) {  
		                    // TODO: handle exception  
		                    ex.printStackTrace();  
		                }  
		            }  
			}
			 else
				 JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE); 
		}
	}
//	private class SwingAction_2 extends AbstractAction {
//		/**
//		 * 
//		 */
//		private static final long serialVersionUID = 1L;
//		private Desktop desktop;
//		public SwingAction_2() {
//			putValue(NAME, "枚举型常量");
//			putValue(SHORT_DESCRIPTION, "Some short description");
//		}
//		public void actionPerformed(ActionEvent e) {
//			 if(lblNewLabel.getText()!=""){
//				  if (Desktop.isDesktopSupported()) {  
//		                desktop = Desktop.getDesktop();  
//		                try {  
//		                    desktop.open(new File(CfenxiGUI.getStr()+"MeijuCL.txt"));  
//		                } catch (Exception ex) {  
//		                    // TODO: handle exception  
//		                    ex.printStackTrace();  
//		                }  
//		            }  
//			}
//			 else
//				 JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE); 
//		}
//	}
//	private class SwingAction_3 extends AbstractAction {
//		/**
//		 * 
//		 */
//		private static final long serialVersionUID = 1L;
//		private Desktop desktop;
//		public SwingAction_3() {
//			putValue(NAME, "整型常量");
//			putValue(SHORT_DESCRIPTION, "Some short description");
//		}
//		public void actionPerformed(ActionEvent e) {
//			 if(lblNewLabel.getText()!=""){
//				  if (Desktop.isDesktopSupported()) {  
//		                desktop = Desktop.getDesktop();  
//		                try {  
//		                    desktop.open(new File(CfenxiGUI.getStr()+"ZhengxingCL.txt"));  
//		                } catch (Exception ex) {  
//		                    // TODO: handle exception  
//		                    ex.printStackTrace();  
//		                }  
//		              
//			}
//			
//		} else
//				 JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE); 
//		}
//	}
//	private class SwingAction_4 extends AbstractAction {
//		/**
//		 * 
//		 */
//		private static final long serialVersionUID = 1L;
//		private Desktop desktop;
//		public SwingAction_4() {
//			putValue(NAME, "字符型常量");
//			putValue(SHORT_DESCRIPTION, "Some short description");
//		}
//		public void actionPerformed(ActionEvent e) {
//			 if(lblNewLabel.getText()!=""){
//				  if (Desktop.isDesktopSupported()) {  
//		                desktop = Desktop.getDesktop();  
//		                try {  
//		                    desktop.open(new File(CfenxiGUI.getStr()+"ZifuxingCL.txt"));  
//		                } catch (Exception ex) {  
//		                    // TODO: handle exception  
//		                    ex.printStackTrace();  
//		                }  
//		            }  
//			}
//			 else
//				 JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE); 
//		
//		}
//	}
//	private class SwingAction_5 extends AbstractAction {
//		/**
//		 * 
//		 */
//		private static final long serialVersionUID = 1L;
//		private Desktop desktop;
//		public SwingAction_5() {
//			putValue(NAME, "字符串型常量");
//			putValue(SHORT_DESCRIPTION, "Some short description");
//		}
//		public void actionPerformed(ActionEvent e) {
//			 if(lblNewLabel.getText()!=""){
//				  if (Desktop.isDesktopSupported()) {  
//		                desktop = Desktop.getDesktop();  
//		                try {  
//		                    desktop.open(new File(CfenxiGUI.getStr()+"ZifuchuanxingCL.txt"));  
//		                } catch (Exception ex) {  
//		                    // TODO: handle exception  
//		                    ex.printStackTrace();  
//		                }  
//		            }  
//			}
//			 else
//				 JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE); 
//		}
//	}
//	private class SwingAction_6 extends AbstractAction {
//		/**
//		 * 
//		 */
//		private static final long serialVersionUID = 1L;
//		private Desktop desktop;
//		public SwingAction_6() {
//			putValue(NAME, "标识符");
//			putValue(SHORT_DESCRIPTION, "Some short description");
//		}
//		public void actionPerformed(ActionEvent e) {
//			if(lblNewLabel.getText()!=""){
//				if(Desktop.isDesktopSupported()){
//					desktop = Desktop.getDesktop();
//					try{
//						desktop.open(new File(CfenxiGUI.getStr()+"BiaoshiFu.txt"));
//					}catch(Exception ex){
//						ex.printStackTrace();
//					}
//				}
//			}
//			else{
//				JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE);
//			}
//		}
//	}
//	private class SwingAction_7 extends AbstractAction {
//		/**
//		 * 
//		 */
//		private static final long serialVersionUID = 1L;
//		private Desktop desktop;
//		public SwingAction_7() {
//			putValue(NAME, "基本字");
//			putValue(SHORT_DESCRIPTION, "Some short description");
//		}
//		public void actionPerformed(ActionEvent e) {
//			if(lblNewLabel.getText()!=""){
//				if(Desktop.isDesktopSupported()){
//					desktop=Desktop.getDesktop();
//					try {
//						desktop.open(new File(CfenxiGUI.getStr()+"JibenZi.txt"));
//					} catch (IOException e1) {
//						// TODO Auto-generated catch block
//						e1.printStackTrace();
//					}
//				}
//				}else{
//					JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE);
//		}
//			}
//	}
//	private class SwingAction_8 extends AbstractAction {
//		/**
//		 * 
//		 */
//		private static final long serialVersionUID = 1L;
//		private Desktop desktop;
//		public SwingAction_8() {
//			putValue(NAME, "界符");
//			putValue(SHORT_DESCRIPTION, "Some short description");
//		}
//		public void actionPerformed(ActionEvent e) {
//			if(lblNewLabel.getText()!=""){
//				if(Desktop.isDesktopSupported()){
//					desktop=Desktop.getDesktop();
//					try {
//						desktop.open(new File(CfenxiGUI.getStr()+"JieFu.txt"));
//					} catch (IOException e1) {
//						// TODO Auto-generated catch block
//						e1.printStackTrace();
//					}
//				}
//			}else{
//				JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE);
//			}
//		}
//	}
//	private class SwingAction_9 extends AbstractAction {
//		/**
//		 * 
//		 */
//		private static final long serialVersionUID = 1L;
//		private Desktop desktop;
//		public SwingAction_9() {
//			putValue(NAME, "运算符");
//			putValue(SHORT_DESCRIPTION, "Some short description");
//		}
//		public void actionPerformed(ActionEvent e) {
//			if(lblNewLabel.getText()!=""){
//				if(Desktop.isDesktopSupported()){
//					desktop=Desktop.getDesktop();
//					try {
//						desktop.open(new File(CfenxiGUI.getStr()+"YunsuanFu.txt"));
//					} catch (IOException e1) {
//						// TODO Auto-generated catch block
//						e1.printStackTrace();
//					}
//				}
//			}else{
//				JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE);
//			}
//		}
//	}
	private class SwingAction_10 extends AbstractAction {
		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		private Desktop desktop;
		public SwingAction_10() {
			putValue(NAME, "输出结果");
			putValue(SHORT_DESCRIPTION, "Some short description");
		}
		public void actionPerformed(ActionEvent e) {
			if(lblNewLabel.getText()!=""){
				if(Desktop.isDesktopSupported()){
					desktop=Desktop.getDesktop();
					try {
						desktop.open(new File(CfenxiGUI.getStr()+"output.txt"));
					} catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
			}
			else {
				JOptionPane.showMessageDialog(null, "请先选择文件", "错误",JOptionPane.ERROR_MESSAGE);
			}
		}
	}
}
