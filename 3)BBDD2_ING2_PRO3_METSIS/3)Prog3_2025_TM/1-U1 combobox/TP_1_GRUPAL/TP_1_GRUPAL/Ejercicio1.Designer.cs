namespace TP_1_GRUPAL
{
    partial class Ejercicio1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
      this.lblIngreseNombre = new System.Windows.Forms.Label();
      this.tbCin = new System.Windows.Forms.TextBox();
      this.btnAgrgegar = new System.Windows.Forms.Button();
      this.lbxIzquierda = new System.Windows.Forms.ListBox();
      this.lbxDerecha = new System.Windows.Forms.ListBox();
      this.btnPasarUno = new System.Windows.Forms.Button();
      this.btnPasarTodos = new System.Windows.Forms.Button();
      this.SuspendLayout();
      // 
      // lblIngreseNombre
      // 
      this.lblIngreseNombre.AutoSize = true;
      this.lblIngreseNombre.Location = new System.Drawing.Point(13, 31);
      this.lblIngreseNombre.Name = "lblIngreseNombre";
      this.lblIngreseNombre.Size = new System.Drawing.Size(98, 13);
      this.lblIngreseNombre.TabIndex = 0;
      this.lblIngreseNombre.Text = "Ingrese un nombre:";
      // 
      // tbCin
      // 
      this.tbCin.Location = new System.Drawing.Point(117, 28);
      this.tbCin.Name = "tbCin";
      this.tbCin.Size = new System.Drawing.Size(166, 20);
      this.tbCin.TabIndex = 1;
      // 
      // btnAgrgegar
      // 
      this.btnAgrgegar.Location = new System.Drawing.Point(313, 26);
      this.btnAgrgegar.Name = "btnAgrgegar";
      this.btnAgrgegar.Size = new System.Drawing.Size(75, 23);
      this.btnAgrgegar.TabIndex = 2;
      this.btnAgrgegar.Text = "Agregar";
      this.btnAgrgegar.UseVisualStyleBackColor = true;
      this.btnAgrgegar.Click += new System.EventHandler(this.btnAgrgegar_Click);
      // 
      // lbxIzquierda
      // 
      this.lbxIzquierda.FormattingEnabled = true;
      this.lbxIzquierda.Location = new System.Drawing.Point(12, 86);
      this.lbxIzquierda.Name = "lbxIzquierda";
      this.lbxIzquierda.Size = new System.Drawing.Size(112, 147);
      this.lbxIzquierda.TabIndex = 3;
      // 
      // lbxDerecha
      // 
      this.lbxDerecha.FormattingEnabled = true;
      this.lbxDerecha.Location = new System.Drawing.Point(289, 86);
      this.lbxDerecha.Name = "lbxDerecha";
      this.lbxDerecha.Size = new System.Drawing.Size(112, 147);
      this.lbxDerecha.TabIndex = 4;
      // 
      // btnPasarUno
      // 
      this.btnPasarUno.Location = new System.Drawing.Point(165, 106);
      this.btnPasarUno.Name = "btnPasarUno";
      this.btnPasarUno.Size = new System.Drawing.Size(75, 23);
      this.btnPasarUno.TabIndex = 5;
      this.btnPasarUno.Text = ">";
      this.btnPasarUno.UseVisualStyleBackColor = true;
      this.btnPasarUno.Click += new System.EventHandler(this.btnPasarUno_Click);
      // 
      // btnPasarTodos
      // 
      this.btnPasarTodos.Location = new System.Drawing.Point(165, 156);
      this.btnPasarTodos.Name = "btnPasarTodos";
      this.btnPasarTodos.Size = new System.Drawing.Size(75, 23);
      this.btnPasarTodos.TabIndex = 6;
      this.btnPasarTodos.Text = ">>";
      this.btnPasarTodos.UseVisualStyleBackColor = true;
      this.btnPasarTodos.Click += new System.EventHandler(this.btnPasarTodos_Click);
      // 
      // Ejercicio1
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(430, 245);
      this.Controls.Add(this.btnPasarTodos);
      this.Controls.Add(this.btnPasarUno);
      this.Controls.Add(this.lbxDerecha);
      this.Controls.Add(this.lbxIzquierda);
      this.Controls.Add(this.btnAgrgegar);
      this.Controls.Add(this.tbCin);
      this.Controls.Add(this.lblIngreseNombre);
      this.Name = "Ejercicio1";
      this.Text = "Nombres";
      this.ResumeLayout(false);
      this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblIngreseNombre;
        private System.Windows.Forms.TextBox tbCin;
        private System.Windows.Forms.Button btnAgrgegar;
        private System.Windows.Forms.ListBox lbxIzquierda;
        private System.Windows.Forms.ListBox lbxDerecha;
        private System.Windows.Forms.Button btnPasarUno;
        private System.Windows.Forms.Button btnPasarTodos;
    }
}