package edu.tjut.cs;

import java.text.SimpleDateFormat;
import java.util.Date;

import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

@EnableScheduling
@Component
public class ScheduleDemo {

	@Scheduled(cron = "0 0/1 * * * ?") // 每分钟执行一次
	public void work() throws Exception {
		System.out.println("每分钟执行一次的定时任务：" + new SimpleDateFormat("HH:mm:ss").format(new Date()));
	}

	@Scheduled(cron = "0/2 * * * * ?") // 每2秒执行一次
	public void doSomething() throws Exception {
		System.out.println("每2秒执行一个的定时任务：" + new SimpleDateFormat("HH:mm:ss").format(new Date()));
	}

	@Scheduled(cron = "0,15,30,45 * * * * ?") // 每15秒执行一次
	public void doOther() throws Exception {
		System.out.println("每15秒执行一个的定时任务：" + new SimpleDateFormat("HH:mm:ss").format(new Date()));
	}
	
	@Scheduled(initialDelay = 10000, fixedRate = 7000) // 每7秒执行一次
	public void goWork() throws Exception {
		System.out.println("每7秒执行的定时任务：" + new SimpleDateFormat("HH:mm:ss").format(new Date()));
	}
}
