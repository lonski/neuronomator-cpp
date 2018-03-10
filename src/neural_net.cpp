#include "neural_net.h"
#include <algorithm>

NeuralNetwork::NeuralNetwork() {}

NeuralNetwork::~NeuralNetwork() {
  for (Synapse *s : m_synapses) {
    delete s;
  }
  for (Layer *l : m_layers) {
    delete l;
  }
}

void NeuralNetwork::addLayer(Layer *layer) {
  m_layers.push_back(layer);
  if (m_layers.size() > 1) {
    Layer *previousLayer = m_layers[m_layers.size() - 2];
    connectLayers(previousLayer, layer);
  }
}

void NeuralNetwork::connectLayers(Layer *l1, Layer *l2) {
  for (Neuron *left : l1->neurons) {
    for (Neuron *right : l2->neurons) {
      Synapse *synapse = new Synapse(left, right, 0.0);
      m_synapses.push_back(synapse);
    }
  }
}
