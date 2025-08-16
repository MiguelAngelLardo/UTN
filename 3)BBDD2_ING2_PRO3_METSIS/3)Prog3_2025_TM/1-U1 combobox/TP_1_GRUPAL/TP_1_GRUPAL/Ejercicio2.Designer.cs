namespace TP_1_GRUPAL
{
    partial class Ejercicio2
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
      this.gbIngresoDatos = new System.Windows.Forms.GroupBox();
      this.btnAgregar = new System.Windows.Forms.Button();
      this.tbApellido = new System.Windows.Forms.TextBox();
      this.tbNombre = new System.Windows.Forms.TextBox();
      this.lblApellido = new System.Windows.Forms.Label();
      this.lblNombre = new System.Windows.Forms.Label();
      this.gbElementos = new System.Windows.Forms.GroupBox();
      this.btnBorrar = new System.Windows.Forms.Button();
      this.lbxElementos = new System.Windows.Forms.ListBox();
      this.gbIngresoDatos.SuspendLayout();
      this.gbElementos.SuspendLayout();
      this.SuspendLayout();
      // 
      // gbIngresoDatos
      // 
      this.gbIngresoDatos.Controls.Add(this.btnAgregar);
      this.gbIngresoDatos.Controls.Add(this.tbApellido);
      this.gbIngresoDatos.Controls.Add(this.tbNombre);
      this.gbIngresoDatos.Controls.Add(this.lblApellido);
      this.gbIngresoDatos.Controls.Add(this.lblNombre);
      this.gbIngresoDatos.Location = new System.Drawing.Point(12, 66);
      this.gbIngresoDatos.Name = "gbIngresoDatos";
      this.gbIngresoDatos.Size = new System.Drawing.Size(202, 286);
      this.gbIngresoDatos.TabIndex = 0;
      this.gbIngresoDatos.TabStop = false;
      this.gbIngresoDatos.Text = "Ingreso de Datos";
      // 
      // btnAgregar
      // 
      this.btnAgregar.Location = new System.Drawing.Point(33, 164);
      this.btnAgregar.Name = "btnAgregar";
      this.btnAgregar.Size = new System.Drawing.Size(75, 23);
      this.btnAgregar.TabIndex = 4;
      this.btnAgregar.Text = "Agregar";
      this.btnAgregar.UseVisualStyleBackColor = true;
      this.btnAgregar.Click += new System.EventHandler(this.btnAgregar_Click);
      // 
      // tbApellido
      // 
      this.tbApellido.Location = new System.Drawing.Point(61, 110);
      this.tbApellido.Name = "tbApellido";
      this.tbApellido.Size = new System.Drawing.Size(135, 20);
      this.tbApellido.TabIndex = 3;
      // 
      // tbNombre
      // 
      this.tbNombre.Location = new System.Drawing.Point(61, 57);
      this.tbNombre.Name = "tbNombre";
      this.tbNombre.Size = new System.Drawing.Size(135, 20);
      this.tbNombre.TabIndex = 2;
      // 
      // lblApellido
      // 
      this.lblApellido.AutoSize = true;
      this.lblApellido.Location = new System.Drawing.Point(7, 110);
      this.lblApellido.Name = "lblApellido";
      this.lblApellido.Size = new System.Drawing.Size(50, 13);
      this.lblApellido.TabIndex = 1;
      this.lblApellido.Text = "Apellido: ";
      // 
      // lblNombre
      // 
      this.lblNombre.AutoSize = true;
      this.lblNombre.Location = new System.Drawing.Point(7, 57);
      this.lblNombre.Name = "lblNombre";
      this.lblNombre.Size = new System.Drawing.Size(47, 13);
      this.lblNombre.TabIndex = 0;
      this.lblNombre.Text = "Nombre:";
      // 
      // gbElementos
      // 
      this.gbElementos.Controls.Add(this.lbxElementos);
      this.gbElementos.Controls.Add(this.btnBorrar);
      this.gbElementos.Location = new System.Drawing.Point(220, 66);
      this.gbElementos.Name = "gbElementos";
      this.gbElementos.Size = new System.Drawing.Size(180, 286);
      this.gbElementos.TabIndex = 1;
      this.gbElementos.TabStop = false;
      this.gbElementos.Text = "Elementos";
      // 
      // btnBorrar
      // 
      this.btnBorrar.Location = new System.Drawing.Point(43, 247);
      this.btnBorrar.Name = "btnBorrar";
      this.btnBorrar.Size = new System.Drawing.Size(75, 23);
      this.btnBorrar.TabIndex = 0;
      this.btnBorrar.Text = "Borrar";
      this.btnBorrar.UseVisualStyleBackColor = true;
      this.btnBorrar.Click += new System.EventHandler(this.btnBorrar_Click);
      // 
      // lbxElementos
      // 
      this.lbxElementos.FormattingEnabled = true;
      this.lbxElementos.Location = new System.Drawing.Point(6, 19);
      this.lbxElementos.Name = "lbxElementos";
      this.lbxElementos.Size = new System.Drawing.Size(154, 212);
      this.lbxElementos.Sorted = true;
      this.lbxElementos.TabIndex = 1;
      // 
      // Ejercicio2
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(422, 364);
      this.Controls.Add(this.gbElementos);
      this.Controls.Add(this.gbIngresoDatos);
      this.Name = "Ejercicio2";
      this.Text = "Nombe y Apellido";
      this.gbIngresoDatos.ResumeLayout(false);
      this.gbIngresoDatos.PerformLayout();
      this.gbElementos.ResumeLayout(false);
      this.ResumeLayout(false);

        }

    #endregion

    private System.Windows.Forms.GroupBox gbIngresoDatos;
    private System.Windows.Forms.GroupBox gbElementos;
    private System.Windows.Forms.Label lblApellido;
    private System.Windows.Forms.Label lblNombre;
    private System.Windows.Forms.TextBox tbApellido;
    private System.Windows.Forms.TextBox tbNombre;
    private System.Windows.Forms.Button btnAgregar;
    private System.Windows.Forms.Button btnBorrar;
    private System.Windows.Forms.ListBox lbxElementos;
  }
}