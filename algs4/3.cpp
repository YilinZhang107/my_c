#include "windows.h" 
#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

//加权有向边的数据类型
class DirectedEdge {
private:
	int v;//边的起点
	int w;//终点
	double weight;//边的权重

public:
	DirectedEdge(int v=0, int w=0, double weight=-1) {
		this->v = v;
		this->w = w;
		this->weight = weight;
	}
	void initDirectedEdge(int v, int w, double weight = -1) {
		this->v = v;
		this->w = w;
		this->weight = weight;
	}
	double getweight() {return weight;}
	int from() {return v;}
	int to() { return w; }
	string toString() {  //对象的字符串表示
		string s = to_string(v)+"->"+to_string(w)+":"+to_string(weight);
		return s;
	}
};
//加权有向图的数据类型
class EdgeWeightedDigraph {
private:
	int V;//顶点总数
	int E;//边总数
	vector<vector<DirectedEdge> > adj;//邻接表

public:
	EdgeWeightedDigraph(int V) {  //含有v个顶点的空有向图
		this->V = V;
		this->E = 0;
		adj.resize(V);
	}
	//EdgeWeightedDigraph(In in)//从输入流中读取图的构造函数
	int getV() { return V; }
	int getE() { return E; }
	void addEdge(DirectedEdge e) {
		adj[e.from()].push_back(e);//找到这条边的起点并添加到邻接表中
		E++;//边总数+1
	}
	vector<DirectedEdge>* getadj(int v) {//返回从v指出的所有边,接收时注意使用引用
		vector<DirectedEdge>* adjIter = &adj[v];
		return adjIter;
	}
	vector<DirectedEdge>* edges() {//返回图中所有边
		vector<DirectedEdge> *bag = new vector<DirectedEdge>;
		for (int v = 0; v < V; v++) {
			for (auto i = adj[v].begin(); i != adj[v].end(); i++)
				bag->push_back(*i);
		}
		return bag;
	}
};

//点的数据类型
class Point {
private:
	int n;//序号
	int x;//x和y坐标
	int y;
public:
	Point(int N = 0, int X = 0, int Y = 0) :n(N), x(X), y(Y) {}
	void initPoint(int N, int X, int Y) {
		this->n = N;
		this->x = X;
		this->y = Y;
	}
	int getX() { return x; }
	int getY() { return y; }
	static double calWeight(Point& p1, Point& p2) {//计算两点间欧氏距离即权重
		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	}
	void show() { cout << n << ":" << x << "," << y << endl; }
};

//优先队列的实现
template<class Key>
class IndexMinPQ {
private:
	int N;//PQ中的元素数量
	int* pq;//索引二叉堆,从1开始
	int* qp;//逆序:qp[pq[i]] = pq[qp[i]] = i
	Key* keys;//有优先级之分的元素
	bool less(int i, int j) {
		int ki = pq[i];
		int kj = pq[j];
		return keys[ki] > keys[kj];
	}
	void exch(int i, int j) {
		int t = pq[i]; pq[i] = pq[j]; pq[j] = t;
		int qpi = pq[i];
		int qpj = pq[j];
		qp[qpi] = i;
		qp[qpj] = j;
	}
	void swim(int k) {
		while (k > 1 && less(k / 2, k)) {
			exch(k / 2, k);
			k = k / 2;
		}
	}
	void sink(int k) {
		while (2 * k <= N) {
			int j = 2 * k;
			if (j < N && less(j, j + 1))j++;
			if (!less(k, j))break;
			exch(k, j);
			k = j;
		}
	}
public:
	IndexMinPQ(int maxN) {
		N = 0;
		keys = new Key[maxN + 1];
		pq = new int[maxN + 1];
		qp = new int[maxN + 1];
		for (int i = 0; i <= maxN; i++) {
			qp[i] = -1;
		}
	}
	~IndexMinPQ() { delete pq, qp, keys; }
	bool isEmpty() { return N == 0; }
	void toEmpty() { N = 0; }
	bool contains(int k) { return qp[k] != -1; }//是否存在索引为k 的元素
	void insert(int k, Key key) {//插入一个元素,将它和索引k相关联
		N++;
		qp[k] = N;
		pq[N] = k;
		keys[k] = key;
		swim(N);
	}
	void change(int k, Key key) {//将索引k 的元素设为key
		keys[k] = key;
		swim(qp[k]);
		sink(qp[k]);
	}
	int delMin() {//删除最小元素并返回它的索引
		int indexOfMin = pq[1];
		exch(1, N--);
		sink(1);
		keys[pq[N + 1]] = NULL;
		qp[pq[N + 1]] = -1;
		return indexOfMin;
	}
	Key getMin() { //返回最小元素
		return keys[pq[1]];
	}


};
//对被查找过的边更换颜色
void DrawLine(int p1, int p2, Point* P) {
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glLineWidth(10.0);
	glVertex2f(P[p1].getX(), P[p1].getY());
	glVertex2f(P[p2].getX(), P[p2].getY());
	glEnd();
	glFlush();    //是否即时的显示扫描过的线路
	Sleep(0.1);
}
//查找最短路径
class DijkstraSP {
private:
	DirectedEdge* edgeTo;
	double* distTo;
	double* DistTo;
	IndexMinPQ<double>* pq;//优先队列
	
	void relax(EdgeWeightedDigraph* G, int v,int end, Point* P){//顶点的松弛
		vector<DirectedEdge>* E = G->getadj(v);
		for (auto e = E->begin(); e != E->end(); e++) {
			
			int w = e->to();
			DrawLine(e->from(),w, P);
			if (DistTo[w] > DistTo[v]-Point::calWeight(P[v], P[end]) + e->getweight()+ Point::calWeight(P[w], P[end])) {
			//if (distTo[w] > distTo[v] + e->getweight()) { //第二种改进方式
				DistTo[w] = DistTo[v] - Point::calWeight(P[v], P[end]) + e->getweight() + Point::calWeight(P[w], P[end]);
				distTo[w] = distTo[v] + e->getweight();
				edgeTo[w] = *e;
				if (pq->contains(w))
					//pq->change(w, distTo[w]);
					pq->change(w, DistTo[w]);
				else
					//pq->insert(w, distTo[w]);
					pq->insert(w, DistTo[w]);
			}
			if (w == end) {//发现目的地就停止搜索
				pq->toEmpty();
				return;
			}
		}
	}

public:
	DijkstraSP(EdgeWeightedDigraph *G,int s,int end, Point* P) {//G:有向图  s:起始点
		clock_t start, to;//记录时间
		start = clock();
		edgeTo = new DirectedEdge[G->getV()];//s到v的最短路径上的最后一条边
		distTo = new double[G->getV()];//dist[w]是从s到w的最短路径的长度
		DistTo = new double[G->getV()];//DistTo = distTo+distant(v,t),加上到终点的直线距离
		pq = new IndexMinPQ<double>(G->getV());
		for (int v = 0; v < G->getV(); v++) {
			distTo[v] = DBL_MAX;//初始化赋予最大值
			DistTo[v] = DBL_MAX;//初始化赋予最大值
		}
		distTo[s] = 0.0;
		DistTo[s] = distTo[s]+Point::calWeight(P[s],P[end]);
		pq->insert(s, 0.0);
		to = clock();
		cout << "time = " << double(to - start) / CLOCKS_PER_SEC << "s" << endl;
		while (!pq->isEmpty()) {
			relax(G, pq->delMin(),end,P);
		}
	}
	~DijkstraSP() {
		delete edgeTo, distTo, pq,DistTo;
	}
	double getDistTo(int v) {return distTo[v];}
	bool hasPathTo(int v) { return distTo[v] < DBL_MAX; }
	vector<DirectedEdge>* pathTo(int v) {//传回的是一个结果的vector
		if (!hasPathTo(v))return NULL;
		vector<DirectedEdge> *path = new vector<DirectedEdge>();
		for (DirectedEdge e = edgeTo[v]; e.getweight() != -1; e = edgeTo[e.from()]) {
			path->insert(path->begin(),e);
		}
		return path;
	}
};


//画图相关 窗口大小改变时
void ChangeSize(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-1000, 13000.0, -1000.0 * (GLfloat)h / (GLfloat)w, 6187.5 * (GLfloat)h / (GLfloat)w, -50.0, 50.0);
	else
		glOrtho(-1000 * (GLfloat)h / (GLfloat)w, 13000.0 * (GLfloat)h / (GLfloat)w, -1000.0, 6187.5, -50.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//画出所有边
void DrawEdges(vector<DirectedEdge> *de, Point *P) {
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 1.0);
	for (auto i = de->begin(); i != de->end(); i++) {
		glVertex2f(P[i->from()].getX(), P[i->from()].getY());
		glVertex2f(P[i->to()].getX(), P[i->to()].getY());
	}
	glEnd();
}
//对最短路径描边
void DrawPaths(vector<DirectedEdge>* de, Point* P) {
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0);
	for (auto i = de->begin(); i != de->end(); i++) {
		glVertex2f(P[i->from()].getX(), P[i->from()].getY());
		glVertex2f(P[i->to()].getX(), P[i->to()].getY());
	}
	glEnd();
}

//真正的主函数(因为RenderScene没法传参)
void RenderScene()
{   
	ifstream infile;
	infile.open("D://Codes/C/3Map.txt", ios::in);
	int V, E;//顶点和边的总数
	infile >> V >> E;
	//cout << V << E;
	//创建有向图
	EdgeWeightedDigraph* G = new EdgeWeightedDigraph(V);
	Point* P = new Point[V];
	int N, X, Y;
	for (int i = 0; i < V; i++) {
		infile >> N >> X >> Y;
		//cout << N << X << Y;
		P[i].initPoint(N, X, Y);//获得点数据
	}
	//获得边数据
	int v, w;
	for (int i = 0; i < E; i++) {
		infile >> v >> w;
		double weight = Point::calWeight(P[v], P[w]);
		DirectedEdge* e = new DirectedEdge(v, w,weight);
		//cout << v << ' ' << w << endl;
		G->addEdge(*e);
		e = new DirectedEdge(w, v, weight);
		G->addEdge(*e);
		delete e;
	}
	
	int from, to;//记录起点和终点
	while (true) {
		cout << "please input from and to: ";
		cin >> from >> to;
		cout << endl;
		
		//退出程序
		if (from == -1 && to == -1)
			exit(0);

		//画出全部路线
		vector<DirectedEdge>* de = new vector<DirectedEdge>;
		de = G->edges();
		glClear(GL_COLOR_BUFFER_BIT);
		DrawEdges(de, P);
		glFlush();
		clock_t start, end;//记录时间
		start = clock();
		//找到最短路径打印并画出
		DijkstraSP* Dij = new DijkstraSP(G, from, to, P);//起点
		vector<DirectedEdge>* result = Dij->pathTo(to);//终点
		end = clock();

		if (result != NULL) {
			DrawPaths(result, P);
			for (auto i = result->begin(); i != result->end(); i++) {
				cout << i->toString() << endl;
			}
			cout << "distant= "<<Dij->getDistTo(to)<< endl;
			cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
		}
		else {
			cout << "There is no shortest path from " << from << " to " << to << endl;
			cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
		}

		glFlush();
		/*
		for (int i = 0; i < 10; i++) {
			P[i].show();
		}*/
		delete Dij;
	}
	delete G, P;
}

int main(int argc, char* argv[]) {
	//画图
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1100, 900);
	glutInitWindowPosition(500, 100);

	glutCreateWindow("Map");
	glClearColor(1.0, 1.0, 1.0, 0.0); 
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);  //窗口大小改变时

	/*优先队列测试
	IndexMinPQ<double> pq(10);
	pq.insert(1, 0.0);
	pq.insert(2, 1.0);
	cout << pq.isEmpty() << endl;
	cout << pq.delMin() << endl;
	cout << pq.delMin() << endl;
	cout << pq.contains(2) << endl;
	*/
	glutMainLoop();
	
	//for (auto i = de->begin(); i != de->end(); i++)
		//cout << (i->toString()) << endl;
	return 0;
}