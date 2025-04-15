import java.io.*;
import java.util.*;

public class Solution {

	static int T;
	static int N, M, K;
	static int map[][] = new int[801][801];
	static boolean visit[][];
	static PriorityQueue<ActivateCell> activateQ; //활성상태 -> 번식할 세포 (생명력이 큰 순으로 정렬)
	static PriorityQueue<Cell> deactivateQ; //비활성 또는 번식을 못하는 활성 세포 (곧 활성화될 가능성이 높은 세포순으로 정렬)
	static int d[][] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	static int time; //현재 시간

	static class Cell {
		int x;
		int y;
		int life;
		int createTime;
		boolean isDie;

		public Cell(int x, int y, int life, int createTime, boolean isDie) {
			this.x = x;
			this.y = y;
			this.life = life;
			this.createTime = createTime;
			this.isDie = isDie;
		}
	}
	
	static class ActivateCell {
		int x;
		int y;
		int life;

		public ActivateCell(int x, int y, int life) {
			this.x = x;
			this.y = y;
			this.life = life;
		}
	}

	static void multiplyCell() {
		Cell c;
		ActivateCell ac;
		int nx, ny;
		while (!activateQ.isEmpty()) { //번식할 세포부터 번식 시작
			ac = activateQ.poll();
			for (int i = 0; i < 4; i++) {
				nx = ac.x + d[i][0];
				ny = ac.y + d[i][1];
				if (visit[nx][ny])
					continue;
				//새로운 세포는 비활성상태이며, 현재를 생성 시간으로 가짐
				deactivateQ.offer(new Cell(nx, ny, ac.life, time, false));
				visit[nx][ny] = true;
			}
			if (ac.life > 1) { //생명력이 1보다 큰 세포는 활성화 상태로 유지되어야 하므로
				//죽지 않은 상태로 비활성상태 큐에 들어감 (현재 시간 - 1 + 생명력의 시간 동안은 살아있음)
				//isDie = true -> 비활성 상태에서 추후 죽일 것
				deactivateQ.offer(new Cell(ac.x, ac.y, ac.life, time - 1, true));
			}
		}

		while (!deactivateQ.isEmpty()) { //비활성 상태 (c.createTime + c.life 낮은 순 정렬)
			c = deactivateQ.poll();
			if (c.createTime + c.life == time) { //현재 처리해야 하는 세포이면
				if(c.isDie) { //죽일 세포면 삭제
					continue;
				}else { //새로 활성화될 세포이면 활성화
					activateQ.offer(new ActivateCell(c.x, c.y, c.life));
				}
			} else { //아직 활성화될 시간이 아니면 다시 큐에 담아주고 종료
				deactivateQ.offer(c);
				break;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int cx = 400, cy = 400;

		T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			activateQ = new PriorityQueue<>((a, b) -> b.life - a.life);
			deactivateQ = new PriorityQueue<>((a, b) -> {
				if (a.createTime + a.life == b.createTime + b.life)
					return a.createTime - b.createTime;
				return (a.createTime + a.life) - (b.createTime + b.life);
			});
			time = 0;
			visit = new boolean[801][801];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < M; j++) {
					map[cx + i][cy + j] = Integer.parseInt(st.nextToken());
					if (map[cx + i][cy + j] != 0) {
						//비활성상태로 전부 넣기
						deactivateQ.offer(new Cell(cx + i, cy + j, map[cx + i][cy + j], time, false));
						visit[cx + i][cx + j] = true;
					}
				}
			}

			while (K-- > 0) { // 시간 체크
				time++;
				multiplyCell();
			}

			sb.append("#").append(t).append(" ").append(activateQ.size() + deactivateQ.size()).append("\n");
		}
		System.out.print(sb);
	}

}
