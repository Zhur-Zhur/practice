using System;

public class Node
{
    public int value;
    public Node parent, left_child, right_child;

    public Node(int node_value, Node node_parent = null, Node node_left=null, Node node_right=null)
    {
        this.value = node_value;
        this.parent = node_parent;
        this.left_child = node_left;
        this.right_child = node_right;
    }

    public void set_parent(Node new_parent)
    {
        this.parent = new_parent;
    }

    public void set_left(Node new_left)
    {
        this.left_child = new_left;
        new_left.set_parent(this);
    }

    public void set_right(Node new_right)
    {
        this.right_child = new_right;
        new_right.set_parent(this);
    }

    // inorder successor for a binary tree
    // Worst Time: O(h), where h is height of tree
    public Node inorder_successor()
    {
        Node current = null;
        if (this.right_child != null) // Node has right children successor must be left most node in subtree
        {
            current = this.right_child;
            while (current.left_child != null)
                current = current.left_child;
        }
        else // Node has no right most children
        {
            current = this;
            while (current.parent != null && current.parent.right_child == current) // Travel up till current is no longer right child
                current = current.parent; 
            current = current.parent; // parent which current is left child of or null from root
        }
        return current;
    }

    // String override
    public override string ToString()
    {
        return this.value.ToString();
    }

    public void in_order()
    {
        if (this.left_child != null)
            this.left_child.in_order();
        Console.WriteLine(this.value);
        if (this.right_child != null)
            this.right_child.in_order();
    }
}

public class InOrder_Successor
{
    static void Main(string[] args)
    {
        Node n0 = new Node(0);
        Node n1 = new Node(1);
        Node n2 = new Node(2);
        Node n3 = new Node(3); // Root
        Node n4 = new Node(4);
        Node n5 = new Node(5);
        Node n6 = new Node(6);
        Node n7 = new Node(7);
        n1.set_left(n0);
        n1.set_right(n2);
        n3.set_left(n1);
        n3.set_right(n5);
        n5.set_left(n4);
        n5.set_right(n7);
        n7.set_left(n6);

        Console.WriteLine("0:"+n0.inorder_successor());
        Console.WriteLine("1:" + n1.inorder_successor());
        Console.WriteLine("2:" + n2.inorder_successor());
        Console.WriteLine("3:" + n3.inorder_successor());
        Console.WriteLine("4:" + n4.inorder_successor());
        Console.WriteLine("5:" + n5.inorder_successor());
        Console.WriteLine("6:" + n6.inorder_successor());
        Console.WriteLine("7:" + n7.inorder_successor());

        Console.WriteLine();
        n3.in_order(); // In order of root
    }
}
