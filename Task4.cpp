#include <iostream>

class mas {

private:
    int m_N = 1;
    int* m_mas = new int[m_N];

public:
    mas(int element) {
        m_N = 1;
        m_mas[0] = element;
    }

    void PushBack(int element) {
        int* ms = new int[m_N + 1];
        for (int i = 0; i < m_N; i++) {
            ms[i] = m_mas[i];
        }
        ms[m_N] = element;
        delete[]m_mas;
        m_mas = ms;
        m_N++;
    }

    int SizeOfMass() {
        return m_N;
    }

    int Element(int index) {
        return m_mas[index];
    }

    void ChangeElement(int index, int element) {
        m_mas[index] = element;
    }

    void DeleteElement(int index) {
        for (int i = index; i < m_N - 1; i++) {
            m_mas[i] = m_mas[i + 1];
        }
        m_N--;
    }

    void InsertElement(int index, int element) {
        int* ms = new int[m_N + 2];
        for (int i = 0; i < index; i++) {
            ms[i] = m_mas[i];
        }
        ms[index] = element;
        for (int i = index + 1; i < m_N + 1; i++) {
            ms[i] = m_mas[i - 1];
        }
        m_N++;
        delete[]m_mas;
        m_mas = ms;
    }

    void Output() {
        for (int i = 0; i < m_N; i++) {
            std::cout << m_mas[i] << " ";
        }
        std::cout << "\n";
    }

};

int main() {
    mas mas1(1);
    mas1.PushBack(2);
    mas1.PushBack(3);
    mas1.PushBack(4);
    mas1.PushBack(5);
    std::cout << "Size of mass: " << mas1.SizeOfMass() << std::endl;
    std::cout << "Element of mass[1]: " << mas1.Element(1) << std::endl;
    mas1.DeleteElement(3);
    std::cout << "Delete(3): " << std::endl;
    mas1.Output();
    mas1.InsertElement(1, 0);
    std::cout << "Insert(1, 0): " << std::endl;
    mas1.Output();
}