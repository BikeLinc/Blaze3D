using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(MeshGenerator))]
public class MeshGenerator : MonoBehaviour
{
	
	Mesh mesh;
	
	Vector3[] vertices;
	int[] triangles;
	Color[] colors;
	float minTerrainHeight = 10;
	float maxTerrainHeight = -10;
	
	// Setup Terrain
	public int xSize = 32;
	public int zSize = 32;

	public int layers = 5;
	public float frequency = 0.02f;
	public float amplitude = 5.0f;
	
	public float waterLevel = 1.0f;

	public Material material;
	public Gradient gradient;

	public bool update = false;
	
	
    void Start() {
        GenMesh();
	}
	
	void GenMesh() {
		mesh = new Mesh();
		GetComponent<MeshFilter>().mesh = mesh;
		CreateShape();
		UpdateMesh();
	}
	
	void CreateShape() {
		vertices = new Vector3[(xSize + 1)*(zSize + 1)];
		
		float[] seeds = CalcLayerSeeds(0, 100000);
		
		for(int i = 0, z = 0; z <= zSize; z++) {
			for(int x = 0; x <= xSize; x++) {
				float y = CalcHeight(seeds, x, z);
				vertices[i] = new Vector3(x, y, z);

				if(y > maxTerrainHeight) {
					maxTerrainHeight = y;
				}
				if(y < minTerrainHeight) {
					minTerrainHeight = y;
				}

				i++;
			}
		}
		
		int vert = 0;
		int tris = 0;
		
		triangles = new int[xSize * zSize * 6];
		for(int z = 0; z < zSize; z++) {
		for(int x = 0; x < xSize; x++) {
			triangles[tris + 0] = vert + 0;
			triangles[tris + 1] = vert + xSize + 1;
			triangles[tris + 2] = vert + 1;
			triangles[tris + 3] = vert + 1;
			triangles[tris + 4] = vert + xSize + 1;
			triangles[tris + 5] = vert + xSize + 2;
			vert++;
			tris+= 6;
		}
			vert++;
		}

		colors = new Color[vertices.Length];
		for(int i = 0, z = 0; z <= zSize; z++) {
			for(int x = 0; x <= xSize; x++) {
				float height = Mathf.InverseLerp(minTerrainHeight, maxTerrainHeight, vertices[i].y);
				colors[i] = gradient.Evaluate(height);
				i++;
			}
		}
	}
	
	private float CalcHeight(float[] seeds, float x, float z) {
		float value = 0f;
		float thisFreq = frequency;
		float thisAmpl = amplitude;
		for (int i = 0; i < seeds.Length; i++) {
			value += Mathf.PerlinNoise(thisFreq * x + seeds[i], thisFreq * z + seeds[i]) * thisAmpl;
			thisFreq *= 2;
			thisAmpl /= 2;
		}
		if(value < waterLevel) {
			value = waterLevel;
		}
		return value;
	}
	
	private float[] CalcLayerSeeds(float min, float max) {
		float[] seeds = new float[layers];
		for(int i = 0; i < seeds.Length; i++) {
			seeds[i] = Random.Range(min, max);
			Debug.Log("Seed" + (i + 1) + ": " + seeds[i]);
		}
		return seeds;
	}

	void UpdateMesh() {
		mesh.Clear();
		mesh.vertices = vertices;
		mesh.triangles = triangles;
		mesh.colors = colors;
		mesh.RecalculateBounds();
		mesh.RecalculateNormals();
		mesh.RecalculateTangents();
	}
	
	private void OnValidate() {
		if(update) {
			Debug.Log("Update");
			update = false;
			GenMesh();
		}
	}
	
	/*
	private void OnDrawGizmos() {
		
		if(vertices == null)
			return;
		
		for(int i = 0; i < vertices.Length; i++) {
			Gizmos.DrawSphere(vertices[i], .1f);
		}
	}
	*/
}
