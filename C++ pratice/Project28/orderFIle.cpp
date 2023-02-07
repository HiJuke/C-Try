#include"orderFile.h"


OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;
	string roomId;
	string interval;
	string StuId;
	string StuName;
	string status;

	this->m_Size = 0;	//預約記錄個數

	while (ifs >> data && ifs >> roomId && ifs >> interval && ifs >> StuId && ifs >> StuName && ifs >> status) {
		string key;
		string value;
		map<string, string> m;

		int pos = data.find(":");
		if(pos != -1){
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = StuId.find(":");
		if (pos != -1) {
			key = StuId.substr(0, pos);
			value = StuId.substr(pos + 1, StuId.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = StuName.find(":");
		if (pos != -1) {
			key = StuName.substr(0, pos);
			value = StuName.substr(pos + 1, StuName.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));
		}

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
}

void OrderFile::updateOrder() {
	if (this->m_Size == 0) {
		return;
	}

	//Date:5 Room:3 Interval:2 StuId:10003 StuName:student03 Status:1
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);	//清空並輸入
	for (int i = 0; i < m_Size; i++) {
		ofs << "Date:" << this->m_orderData[i]["Date"] << " ";
		ofs << "Room:" << this->m_orderData[i]["Room"] << " ";
		ofs << "Interval:" << this->m_orderData[i]["Interval"] << " ";
		ofs << "StuId:" << this->m_orderData[i]["StuId"] << " ";
		ofs << "StuName:" << this->m_orderData[i]["StuName"] << " ";
		ofs << "Status:" << this->m_orderData[i]["Status"] << endl;
	}
	ofs.close();
}
