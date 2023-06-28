#include <iostream>
#include <vector>
#include <functional>
#include <chrono>
// Biblioteca externa: https://github.com/progschj/ThreadPool
#include "ThreadPool.h"

int main() {
    const int numThreads = 4;
    ThreadPool pool(numThreads);

    // armazena os resultados das tarefas
    std::vector<std::future<void>> results;

    // Adiciona tarefas ao pool
    for (int i = 0; i < 10; ++i) {
        results.emplace_back(pool.enqueue([i]() {
            std::cout << "Thread " << std::this_thread::get_id() << " executando tarefa: " << i << std::endl;
            // Simulação de processamento da tarefa
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }));
    }

    // Aguarda a conclusão das tarefas
    for (auto& result : results) {
    result.wait();
    }

    return 0;
}
