#include "MusicType.h"

MusicType::MusicType(){}
MusicType::MusicType(int in_id):m_Id(in_id){}
MusicType::~MusicType() {}

string MusicType::GetType() {
	return m_Type;
}
int MusicType::GetId() {
	return m_Id;
}
string MusicType::GetName() {
	return m_Name;
}
string MusicType::GetComposer() {
	return m_Composer;
}
string MusicType::GetArtist() {
	return m_Artist;
}
string MusicType::GetGenre() {
	return m_Genre;
}
string MusicType::GetLyrics(){
    return m_Lyrics;
}
string MusicType::GetAlbumcover(){
    return m_Albumcover;
}
void MusicType::SetType(string inType) {
	m_Type = inType;
}
void MusicType::SetId(int inId) {
	m_Id = inId;
}

void MusicType::SetName(string inName) {
	m_Name = inName;
}
void MusicType::SetComposer(string inComposer) {
	m_Composer = inComposer;
}
void MusicType::SetArtist(string inArtist) {
	m_Artist = inArtist;
}
void MusicType::SetGenre(string inGenre) {
	m_Genre = inGenre;
}
void MusicType::SetLyrics(string inLyrics){
    m_Lyrics = inLyrics;
}
void MusicType::SetAlbumcover(string inAlbumcover){
    m_Albumcover = inAlbumcover;
}



void MusicType::SetRecord(string inType, string inName, string inComposer, string inArtist, string inGenre, int inId) {
	SetType(inType);
	SetName(inName);
	SetComposer(inComposer);
	SetArtist(inArtist);
	SetGenre(inGenre);
	SetId(inId);
}

int MusicType::ReadDataFromFile(ifstream& fin) {
	if (fin.is_open()) {
        fin >> m_Id >> m_Name >> m_Composer >> m_Artist >> m_Genre >> m_Type >>m_Lyrics >> m_Albumcover;
		return 1;
	}
	return 0;
}
int MusicType::WriteDataToFile(ofstream& fout) {
	if (fout.is_open()) {
        fout << m_Id << '\t' << m_Name << '\t' << m_Composer << '\t' << m_Artist << '\t' << m_Genre << '\t' << m_Type<< '\t' << m_Lyrics << '\t' << m_Albumcover << endl;
		return 1;
	}
	return 0;
}

bool MusicType::operator==(MusicType temp) {
    return this->m_Id == temp.GetId();
}

bool MusicType::operator>(MusicType temp)
{
    return (this->GetId() > temp.GetId());
}


bool MusicType::operator<(MusicType temp)
{
    return (this->GetId() < temp.GetId());
}
