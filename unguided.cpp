#include <iostream>
using namespace std;

struct Node
{
    string nama;
    string nim;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void tambahDepan(string nama, string nim)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
        cout << "Data telah ditambahkan" << endl;
    }

    void tambahBelakang(string nama, string nim)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Data telah ditambahkan" << endl;
    }

    void tambahTengah(string nama, string nim, int posisi)
    {
        if (posisi <= 0)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        Node *temp = head;
        for (int i = 0; i < posisi - 1; i++)
        {
            if (temp == nullptr)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Data telah ditambahkan" << endl;
    }

    void hapusDepan()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Data berhasil dihapus" << endl;
    }

    void hapusBelakang()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            cout << "Data berhasil dihapus" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Data berhasil dihapus" << endl;
    }

    void hapusTengah(int posisi)
    {
        if (posisi <= 0 || head == nullptr)
        {
            cout << "Linked list kosong atau posisi tidak valid" << endl;
            return;
        }
        if (posisi == 1)
        {
            hapusDepan();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < posisi - 2; i++)
        {
            if (temp->next == nullptr)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Data berhasil dihapus" << endl;
    }

    void ubahDepan(string namaBaru, string nimBaru)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
        head->nama = namaBaru;
        head->nim = nimBaru;
        cout << "Data berhasil diubah" << endl;
    }

    void ubahBelakang(string namaBaru, string nimBaru)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->nama = namaBaru;
        temp->nim = nimBaru;
        cout << "Data berhasil diubah" << endl;
    }

    void ubahTengah(string namaBaru, string nimBaru, int posisi)
    {
        if (posisi <= 0 || head == nullptr)
        {
            cout << "Linked list kosong atau posisi tidak valid" << endl;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < posisi - 1; i++)
        {
            if (temp == nullptr)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        temp->nama = namaBaru;
        temp->nim = nimBaru;
        cout << "Data berhasil diubah" << endl;
    }

    void hapusList()
    {
        Node *current = head;
        Node *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        cout << "Linked list berhasil dihapus" << endl;
    }

    void tampilkanData()
    {
        Node *temp = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        while (temp != nullptr)
        {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList linkedList;
    int choice;
    string nama, nim;
    int posisi;

    do
    {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl; // Menu untuk hapus list
        cout << "11. Tampilkan Data" << endl;
        cout << "12. Keluar" << endl;
        cout << "Pilih Operasi : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "-Tambah Depan-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            linkedList.tambahDepan(nama, nim);
            break;
        case 2:
            cout << "-Tambah Belakang-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            linkedList.tambahBelakang(nama, nim);
            break;
        case 3:
            cout << "-Tambah Tengah-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            linkedList.tambahTengah(nama, nim, posisi);
            break;
        case 4:
            cout << "-Ubah Depan-" << endl;
            cout << "Masukkan Nama Baru : ";
            cin >> nama;
            cout << "Masukkan NIM Baru : ";
            cin >> nim;
            linkedList.ubahDepan(nama, nim);
            break;
        case 5:
            cout << "-Ubah Belakang-" << endl;
            cout << "Masukkan Nama Baru : ";
            cin >> nama;
            cout << "Masukkan NIM Baru : ";
            cin >> nim;
            linkedList.ubahBelakang(nama, nim);
            break;
        case 6:
            cout << "-Ubah Tengah-" << endl;
            cout << "Masukkan Nama Baru : ";
            cin >> nama;
            cout << "Masukkan NIM Baru : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            linkedList.ubahTengah(nama, nim, posisi);
            break;
        case 7:
            linkedList.hapusDepan();
            break;
        case 8:
            linkedList.hapusBelakang();
            break;
        case 9:
            cout << "-Hapus Tengah-" << endl;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            linkedList.hapusTengah(posisi);
            break;
        case 10:
            linkedList.hapusList(); // Hapus List
            break;
        case 11:
            linkedList.tampilkanData();
            break;
        case 12:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 12);

    return 0;
}