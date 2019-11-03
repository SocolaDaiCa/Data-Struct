class RelationShip {
public:
	int id1;
	int id2;
};

RelationShip connects[200001];
RelationShip disconnects[200001];
int countCoFriends[10001];
int isCoFriends[10001];
int nConnect, nDisconect, n, res[6], nRes;

void init(int N) {
	nConnect = nDisconect = 0;
	n = N;
}

void add(int id, int F, int a[10]) {
	for(int i = 0; i < F; i++) {
		nConnect++;
		connects[nConnect].id1 = id;
		connects[nConnect].id2 = a[i];
		
		nConnect++;
		connects[nConnect].id2 = id;
		connects[nConnect].id1 = a[i];
	}
	
}

void upfriend(int id1, int id2) {
	nDisconect++;
	disconnects[i].id1 = id1;
	disconnects[i].id2 = id2;
	
	nDisconect++;
	disconnects[i].id2 = id1;
	disconnects[i].id1 = id2;
}
int index;
void swap(int &a, &b) {
	a ^= b ^= a ^= b;
}
void recommend(int id, int list[5]) {
	for(int i = 1; i <= n; i++) {
		isCoFriends[i] = countCoFriends[i] = 0;
	}
	for(int i = 1; i <= nConnect; i++) {
		if(connects[i].id1 != id) continue;
		isCoFriends[connects[i].id2]++;
	}
	for(int i = 1; i <= nDisconect; i++) {
		if(disconnects[i].id1 != id) continue;
		isCoFriends[disconnects[i].id2]--;
	}
	for(int i = 1; i <= nConnect; i++) {
		if(isCoFriends[connects[i].id1]) continue;
		if(!isCoFriends[connects[i].id2]) continue;
		countCoFriends[connects[i].id1]++;
	}
	for(int i = 1; i <= nDisconect; i++) {
		if(isCoFriends[disconnects[i].id1]) continue;
		if(!isCoFriends[disconnects[i].id2]) continue;
		countCoFriends[connects[i].id1]--;
	}
	
	nRes = 0;
	for(int i = 1; i <= n; i++) {
		if(countCoFriends[i] == 0) continue;
		res[++nRes] = i;
		index = nRes;
		while(countCoFriends[res[index]] > countCoFriends[res[index - 1]]) {
			swap(res[index], res[index - 1]);
			--index;
		}
		if(nRes == 6) nRes = 5;
	}
	for(int i = 1; i <= nRes; i++) {
		list[i - 1] = res[i];
	}
	return nRes;
}
